// clang-format off
#include <code-2.hpp>

#include <map>
#include <string>
#include <vector>

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

    std::vector<std::string> ghost_vec;

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

        if (name.at(3) == 'A')
            ghost_vec.emplace_back(name);
    }

    while (true)
    { 
        for (std::string ghost : ghost_vec)
        {
            res++;
        }
    }

    REPORT("Result:\t") << res << std::endl;
    return (0);
}
// clang-format on
