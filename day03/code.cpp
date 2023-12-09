#include <fstream>
#include <iostream>
#include <regex>
#include <map>

#define REPORT(X) std::cout << (X)

bool DoesDigitTouch(std::string &top, std::string mid, std::string &bot, size_t pos)
{
    std::string set("!@#$%^&*+=-_\\;:/?");

    #ifdef DEBUG
    std::cout   << top[pos - 1] << top[pos] << top[pos + 1] << "\n"
                << mid[pos - 1] << mid[pos] << mid[pos + 1] << "\n"
                << bot[pos - 1] << bot[pos] << bot[pos + 1] << "\n" << std::endl;
    #endif
    
    for (int x = -1 ; x <= 1 ; x++)
    {
        if (x == 0)
        {
            if (set.find(top[pos + x]) != std::string::npos ||
                set.find(bot[pos + x]) != std::string::npos
            )
                return (true);
        }
        else 
        {
            if (set.find(top[pos + x]) != std::string::npos ||
                set.find(mid[pos + x]) != std::string::npos ||
                set.find(bot[pos + x]) != std::string::npos
            )
                return (true);
        }
    }
    return (false);
}

bool isPartNumber(std::string &top, std::string mid, std::string &bot, std::smatch &hit)
{
    size_t pos = hit.position();
    size_t len = hit.str().length();

    for (size_t i = 0 ; i < len ; i++)
    {
        if (DoesDigitTouch(top, mid, bot, pos + i))
            return (true);
    }

    return (false);
}

int getSumofNumbers(std::string &top, std::string mid, std::string &bot)
{
    int sum = 0;
    (void) top;
    (void) bot;

    std::regex pattern("\\b\\d+\\b");

    std::sregex_iterator it(mid.begin(), mid.end(), pattern);
    std::sregex_iterator end;

    while (it != end)
    {
        std::smatch hit = *it;

        bool val = isPartNumber(top, mid, bot, hit);
        if (val)
            sum += std::stoi(hit.str());

        #ifdef DEBUG
            if (val)
                std::cout   << "nbr:\t" << it->str() << " is a part nbr" << std::endl;
            else
                std::cout   << "nbr:\t" << it->str() << std::endl;
        #endif

        it++;
    }
    #ifdef DEBUG
        std::cout << std::endl;
    #endif

    return (sum);
}

int main()
{


    std::ifstream infile("input.txt");
    std::string top;
    std::string mid;
    std::string bot;

    std::getline(infile, top);
    std::getline(infile, mid);

    int sum = 0;

    while (std::getline(infile, bot))
    {
        #ifdef DEBUG
            std::cout   << "top:\t" << top << "\n" 
                        << "mid:\t" << mid << "\n"
                        << "bot:\t" << bot << "\n";
        #endif

        sum += getSumofNumbers(top, mid, bot);
        #ifdef DEBUG
            std::cout << std::endl;
        #endif

        top = mid;
        mid = bot;
    }

    std::cout << "sum = " << sum << std::endl;
}