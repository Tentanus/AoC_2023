#include <fstream>
#include <iostream>
#include <regex>
#include <map>

#define REPORT(X) std::cout << (X)

std::map<std::string , int> max_list = {
    {"red", 12},
    {"blue", 14},
    {"green", 13}
    };

bool is_game_possible(std::string result)
{
    #ifdef DEBUG
        REPORT(result) << std::endl;
    #endif

    std::regex pattern("\\b\\d+\\s+(red|blue|green)\\b");

    std::sregex_iterator it(result.begin(), result.end(), pattern);
    std::sregex_iterator end;

    while (it != end)
    {
        std::string hit(it->str());

        std::string col = hit.substr(hit.find_first_of(' ') + 1);
        int max = max_list.at(hit.substr(hit.find_first_of(' ') + 1));
        int hitnbr = std::stoi(hit.substr(0, hit.find_first_of(' ')));

        #ifdef DEBUG
            REPORT(hit) << ":\t" << hitnbr << " " << col << "\t" << max << "\n";
        #endif

        if (max < hitnbr)
        {
            #ifdef DEBUG
                std::cout << std::endl;
            #endif
            return (false);
        }

        it++;
    }

    return (true);
}

int main()
{
    std::ifstream infile("input.txt");
    std::string line;

    unsigned int sum = 0;

    while (std::getline(infile, line))
    {
        if (!is_game_possible(line.substr(line.find_first_of(':') + 1)))
            continue;

        std::string gamenbr = line.substr(0, line.find_first_of(':'));
        gamenbr = gamenbr.substr(gamenbr.find_first_of("0123456789"));

/*
        int tmp = sum;
        #ifdef DEBUG
            REPORT(tmp) << " + " << gamenbr << " = " << sum << std::endl;
        #endif
*/
        sum += std::stoi(gamenbr);
    }
    std::cout << "final sum: " << sum << std::endl;
}