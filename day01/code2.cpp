#include <fstream>
#include <iostream>
#include <array>

#define REPORT(Y,X) std::cout << (Y) << " = " << (X) << std::endl

static const std::string spelled_out[] = 
{
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
};

std::string extractnbr_digit_word(std::string line, size_t pos, bool action, bool rev)
{
//    std::cout << "\nextract: " << (action ? "digit" : "word") << " " << pos << "\t" << line << std::endl;

    if (action == true)
        return (std::to_string(line.at(pos) - '0'));
    
    for (size_t i = 0 ; i < 10 ; i++)
    {
        std::string word = spelled_out[i];

//        std::cout << "\t" << pos << " " << line.find(word) << " " << word << std::endl;

        if (rev == true)
        {
            if (line.rfind(word) != pos)
                continue;
        }
        else
        {
            if (line.find(word) != pos)
                continue;
        }

        return (std::to_string(i));
    }
    return (std::to_string(line.at(line.find_first_of("0123456789"))));
}

int main()
{
    std::ifstream infile("input.txt");
    std::string line;

    unsigned int sum = 0;

    while (std::getline(infile, line))
    {
        std::string nbr;

        size_t posword = std::string::npos;
        for (std::string word : spelled_out)
        {
            size_t postmp = line.find(word);
            if (postmp == std::string::npos)
                continue;

            if (postmp < posword)
                posword = postmp;
        }
        size_t posdigit = line.find_first_of("0123456789");

        if (posdigit < posword)
            nbr += extractnbr_digit_word(line, posdigit, true, false);
        else
            nbr += extractnbr_digit_word(line, posword, false, false);

        std::cout << "first: " << nbr;

// reversing search

        posword = 0;
        for (std::string word : spelled_out)
        {
            size_t postmp = line.rfind(word);
//            std::cout << "tmp: " << postmp << "\tposword: " << posword << word << std::endl;
            if (postmp == std::string::npos)
                continue;
            if (postmp > posword)
                posword = postmp;
        }
        posdigit = line.find_last_of("0123456789");
        if (posdigit == std::string::npos)
            posdigit = 0;

//        std::cout << "\n pos (digit/word): " << posdigit << " " << posword << std::endl;
        if (posdigit >= posword)
            nbr += extractnbr_digit_word(line, posdigit, true, true);
        else
            nbr += extractnbr_digit_word(line, posword, false, true);

        std::cout << " last: " << nbr << "\t" << "line: " << line << std::endl;


        sum += std::stoi(nbr);
    }
    std::cout << "final sum: " << sum << std::endl;
}