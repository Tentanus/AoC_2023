
// clang-format off
#include <code.hpp>

#define REPORT(X) std::cout << (X)

long long delta(long long left, long long right)
{
    return (left - right);
}

void calculateHistory(const std::vector<long> &history, std::vector<long> &next)
{
    for (std::vector<long>::iterator it = history.begin() ;
        it != history.end() - 1 ; it++)
    {
        next.emplace_back(delta(it*, (it + 1)*));
    }
}

int main(int argc, char* argv[])
{
    std::string file = "xinput.txt";
    if (argc != 1)
        file = argv[1];
        
    std::ifstream infile(file);
    std::string line;

    int res = 0;
    std::vector<long> history;

    while (std::getline(infile, line))
    {
        #ifdef DEBUG
            std::cout   << "line:\t\t" << line << "\n";
        #endif
        std::stringstream ss(line);
        std::string option;
        for ( ; std::getline(ss, option, ' ') ; )
        {
                history.emplace_back(std::stoll(option));
        }
    }

    REPORT("Result:\t") << res << std::endl;
    return (0);
}
// clang-format on
