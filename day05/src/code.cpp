#include <fstream>
#include <iostream>
#include <regex>
#include <map>

#include <code.hpp>

#define REPORT(X) std::cout << (X)

int main(int argc, char* argv[])
{
    std::string file = "xinput.txt";
    if (argc != 1)
        file = argv[1];
        
    std::ifstream infile(file);
    std::string line;

    int res = 0;
    while (std::getline(infile, line))
    {
        #ifdef DEBUG
            std::cout   << "line:\t\t" << line << "\n";
        #endif
       

    }

    REPORT("Result:\t") << res << std::endl;
    return (1);
}