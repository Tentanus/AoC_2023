#include <fstream>
#include <iostream>
#include <regex>
#include <map>

#define REPORT(X) std::cout << (X)
#define NBRS "0123456789"

int getNbrfrompos(std::string line, size_t pos)
{
    size_t first = line.substr(0, pos + 1).find_last_not_of(NBRS) + 1;
    size_t last = line.substr(pos).find_first_not_of(NBRS) - 1 + pos;

    return (std::stoi(line.substr(first, last)));
}

void getNbrfromLineHor(std::string line, size_t pos, std::vector<int> &vec)
{
    if (std::isdigit(line[pos - 1]))
        vec.push_back(getNbrfrompos(line, pos - 1));
    if (std::isdigit(line[pos + 1]))
        vec.push_back(getNbrfrompos(line, pos + 1));
}


void getNbrfromLineNonHor(std::string line, size_t pos, std::vector<int> &vec)
{
    if (std::isdigit(line[pos - 1]))
        vec.push_back(getNbrfrompos(line, pos - 1));
    if (std::isdigit(line[pos - 1]) && std::isdigit(line[pos]))
        return ;
    if (std::isdigit(line[pos + 1]))
        vec.push_back(getNbrfrompos(line, pos + 1));
    
}

int getMultofCase(std::string &top, std::string mid, std::string &bot, std::smatch hit)
{
    size_t pos = hit.position();
    std::vector<int> vec;

    getNbrfromLineNonHor(top, pos, vec);
    getNbrfromLineHor(mid, pos, vec);
    getNbrfromLineNonHor(bot, pos, vec);

    for (auto item : vec)
        std::cout << item << " ";
    std::cout << std::endl;
    
    if (vec.size() == 2)
        return (vec[0] * vec[1]);
    else 
        return (0);
}

int getMultofLine(std::string &top, std::string mid, std::string &bot)
{
    int sum = 0;

    std::regex pattern("\\*");

    std::sregex_iterator it(mid.begin(), mid.end(), pattern);
    std::sregex_iterator end;

    while (it != end)
    {
        #ifdef DEBUG
            REPORT(it->str()) << std::endl;
        #endif
        
        sum += getMultofCase(top, mid, bot, *it);

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

        sum += getMultofLine(top, mid, bot);

        #ifdef DEBUG
            std::cout << std::endl;
        #endif

        top = mid;
        mid = bot;
    }

    std::cout << "sum = " << sum << std::endl;
}