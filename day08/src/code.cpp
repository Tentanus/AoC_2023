
// clang-format off
#include <code.hpp>

#include <map>
#include <string>

#define REPORT(X) std::cout << (X)

int main(int argc, char* argv[])
{
    std::string file = "xinput.txt";
    if (argc != 1)
        file = argv[1];
        
    std::ifstream infile(file);
    std::string line;

    std::map<std::string, std::pair<std::string, std::string>> record;

    std::string instruction;
    std::getline(infile, instruction);

    size_t res = 0;
    while (std::getline(infile, line))
    {
        if (line.empty())
            continue;

        std::string name = line.substr(0, 3);

        size_t beg = line.find("(");
        std::string left = line.substr(beg + 1, 3);

        beg = line.find(","); 
        std::string right = line.substr(beg + 2, 3);

        std::pair<std::string, std::string> p{left, right};
        record.emplace(name, p);
    }

/*
    for (auto item : record)
        std::cout << item.first << " | " << item.second.first << " | " << item.second.second << std::endl;
*/
    std::string name = "AAA";
    std::pair<std::string, std::string> p = record.at("AAA");

    size_t i = 0;
    while (name != "ZZZ")
    {
        std::cout << res << " " << i << " " << instruction.at(i) << " " << name << " | L " << p.first << " | R " << p.second << std::endl;
        if (instruction.at(i) == 'R')
            name = p.second;
        else 
            name = p.first;
        
        p = record.find(name)->second;
        res++;
        i++;
        if (i == instruction.size())
            i = 0;
    }

    REPORT("Result:\t") << res << std::endl;
    return (0);
}
// clang-format on
