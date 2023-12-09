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
                res++;
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
    int card = 1;
    int arr[199];
    std::fill_n(arr, 199, 1);
    

    while (std::getline(infile, line))
    {
        #ifdef DEBUG
            std::cout   << "line:\t\t" << line << "\n";
        #endif
        
        size_t cardval = getCardValue(line.substr(line.find_first_of(":") + 1));
        for (size_t i = 1 ; i <= cardval ; i++)
        {
            if (card + i < 199)
                arr[card + i] += arr[card];                 
        }

        REPORT("card ") << card << " [" << arr[card] << "]"
                        << "\twinning numbers: " << cardval 
                        <<std::endl;
        card++;
    }
    for (size_t i = 1 ; i < (size_t) card ; i++)
        sum += arr[i];

    REPORT("SUM:\t") << sum << std::endl;
}