#include <fstream>
#include <iostream>
#include <regex>
#include <map>

#define REPORT(X) std::cout << (X)

int getCardValue(std::string line)
{
    #ifdef DEBUG
        std::cout << "sub-line:\t" << line << "\n";
    #endif
    std::string win = line.substr(0, line.find_first_of("|"));
    std::string nbr = line.substr(line.find_first_of("|") + 1);
    
    std::regex pattern("\\d+");

    std::sregex_iterator it_win(win.begin(), win.end(), pattern);
    std::sregex_iterator it_nbr(nbr.begin(), nbr.end(), pattern);

    std::sregex_iterator end;
    std::sregex_iterator beg = it_win;

    int res = 0;
    while (it_nbr != end)
    {
        while (it_win != end)
        {
            if (it_nbr->str() == it_win->str())
            {
                #ifdef DEBUG
                    REPORT("hit") << " " << it_nbr->str() << "\n";
                #endif
                if (res == 0)
                    res = 1;
                else 
                    res *= 2;
            }
            it_win++;
        }
        it_win = beg;
        it_nbr++;
    }

    #ifdef DEBUG
        REPORT("res =\t") << res << "\n" << std::endl;
    #endif
    return (res);
}

int main()
{
    std::ifstream infile("input.txt");
    std::string line;

    int sum = 0;
    while (std::getline(infile, line))
    {
        #ifdef DEBUG
            std::cout   << "line:\t\t" << line << "\n";
        #endif
        sum += getCardValue(line.substr(line.find_first_of(":") + 1));

    }

    REPORT("SUM:\t") << sum << std::endl;
}