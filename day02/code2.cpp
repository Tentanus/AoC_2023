#include <fstream>
#include <iostream>
#include <regex>
#include <map>

#define REPORT(X) std::cout << (X)

int find_min_game(std::string result)
{
    #ifdef DEBUG
        REPORT(result) << std::endl;
    #endif

    std::regex pattern("\\b\\d+\\s+(red|blue|green)\\b");

    std::sregex_iterator it(result.begin(), result.end(), pattern);
    std::sregex_iterator end;

    int min_red = 0;
    int min_blue = 0;
    int min_green = 0;
    while (it != end)
    {
        std::string hit(it->str());

        std::string col = hit.substr(hit.find_first_of(' ') + 1);
        int hitnbr = std::stoi(hit.substr(0, hit.find_first_of(' ')));

        if (col == "red" && min_red < hitnbr)
            min_red = hitnbr;
        else if (col == "blue" && min_blue < hitnbr)
            min_blue = hitnbr;
        else if (col == "green" && min_green < hitnbr)
            min_green = hitnbr;

        it++;
    }

    return (min_blue * min_green * min_red);
}

int main()
{
    std::ifstream infile("input.txt");
    std::string line;

    unsigned int sum = 0;

    while (std::getline(infile, line))
    {
        sum += find_min_game(line.substr(line.find_first_of(':') + 1));
    }
    std::cout << "final sum: " << sum << std::endl;
}