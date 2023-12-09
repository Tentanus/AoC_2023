#include <fstream>
#include <iostream>

static const std::string spelled_out[] = 
{
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "sevn",
    "eight",
    "nine"
};

int main()
{
    std::ifstream infile("example_input_2.txt");
    std::string line;

    unsigned int sum = 0;

    while (std::getline(infile, line))
    {
        std::string nbr;

        size_t pos_nbr = line.find_first_of("0123456789");

        nbr.push_back(line.at(pos_nbr));
        
        pos_nbr = line.find_last_of("0123456789");

        nbr.push_back(line.at(pos_nbr));
        
        std::cout <<nbr << "\t" << line << std::endl;

        sum += std::stoi(nbr);
    }
    std::cout << "final sum: " << sum << std::endl;
}