#include <day05.hpp>

#include <vector>
#include <sstream>

#define REPORT(X) std::cout << (X)

std::vector<long long> extract_seeds(std::string line)
{
    std::stringstream line_nbr(line);
    std::string nbr;
    std::vector<long long> vec;

    while (line_nbr >> nbr)
    {
        vec.emplace_back(std::stoll(nbr));
    }
    return (vec);
}

int main(int argc, char* argv[])
{
    std::string file = "xinput.txt";
    if (argc != 1)
        file = argv[1];
        
    std::ifstream infile(file);
    std::string line;

    std::getline(infile, line);
    std::vector<long long> seeds = extract_seeds(line.substr(7, line.length() - 7));

    #ifdef DEBUG
        REPORT("Seeds: ");
        for (auto nbr : seeds)
            REPORT(nbr) << " " ;
        std::cout << std::endl;
    #endif

    std::vector<Almap> Almanac;
    
    std::getline(infile,line);
    std::getline(infile, line);
    Almap almap(line);
    
    int res = 0;
    while (std::getline(infile, line))
    {
        if (line.empty())
        {
            Almanac.emplace_back(almap);
            std::getline(infile, line);
            almap = Almap(line);
            continue;
        }
//        #ifdef DEBUG
//            std::cout << "line:\t" << line << "\n";
//        #endif

        mute mapmute(line);
        almap.mutes.emplace_back(mapmute);
    }

    for (Almap alm : Almanac)
    {
        std::cout << alm.from << " to " << alm.to << ":\n";
        for (mute mu : alm.mutes)
        {
            std::cout << mu._src << " " << mu._dst << " " << mu._range << "\n";
        }
    }

    REPORT("Result:\t") << res << std::endl;
    return (1);
}