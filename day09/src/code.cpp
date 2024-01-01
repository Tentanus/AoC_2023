
// clang-format off
#include <code.hpp>

#define REPORT(X) std::cout << (X)

long verschil(long left, long right)
{
    return (right - left);
}

bool calculateHistory(std::vector<long> &history, std::vector<long> &next)
{
    bool flag = true;

    for (std::vector<long>::iterator it = history.begin() ;
        it != (history.end() - 1) ; it++)
    {
        long delta = verschil(*it , *(it + 1));
        next.emplace_back(delta);
//        std::cout << std::to_string(delta) << " " ;
        if (delta != 0)
            flag = false;
    }
//    std::cout << std::endl;
    return (flag);
}

long predictnext(std::vector<long> history)
{
    std::vector<long> next;

    if (calculateHistory(history, next))
    {
//        std::cout << "LOWEST LINE" << std::endl;
        return (history.at(history.size() - 1));
    }
    long val = predictnext(next);

//    std::cout << "VAL: " << std::to_string(val) << std::endl;
    return (history.at(history.size() - 1) + val);
}

int main(int argc, char* argv[])
{
    std::string file = "xinput.txt";
    if (argc != 1)
        file = argv[1];
        
    std::ifstream infile(file);
    std::string line;

    long res = 0;

    while (std::getline(infile, line))
    {
        #ifdef DEBUG
            std::cout   << "line:\t\t" << line << "\n";
        #endif
        std::stringstream ss(line);
        std::string option;

        std::vector<long> history;
        std::vector<long> next;

        for ( ; std::getline(ss, option, ' ') ; )
                history.emplace_back(std::stoll(option));
        
        res += predictnext(history);
    }

    REPORT("Result:\t") << res << std::endl;
    return (0);
}
// clang-format on
