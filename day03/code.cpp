#include <fstream>
#include <iostream>
#include <regex>
#include <map>

#define REPORT(X) std::cout << (X)

int getSUmofNumbers(std::string &top, std::string mid, std::string &bot)
{
    int sum = 0;



    return (sum);
}

int main()
{
    std::ifstream infile("xinput.txt");
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
                        << "bot:\t" << bot << "\n"
                        << std::endl;
        #endif

        sum += getSumofNumbers(top, mid, bot);
    
        top = mid;
        mid = bot;
    }
}