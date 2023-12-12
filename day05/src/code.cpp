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
    Almanac.emplace_back(almap);

    long long res = __LONG_LONG_MAX__;
    long long seed_res;
    for (long long seed : seeds)
    {
        REPORT("seed: ") << seed;
        long long nbr = seed;
        for (Almap alm : Almanac)
        {
            for (mute mu : alm.mutes)
            {
                if (mu.isin_src_range(nbr))
                {
                    nbr = mu.get_dst(nbr);
                    break;
                }
            }
            REPORT(" -> ") << nbr;
        }
        if (nbr < res)
        {
            REPORT(" !NEW LOW!");
            res = nbr;
            seed_res = seed;
        }
        REPORT(std::endl);
    }

    REPORT("Seed:\t") << seed_res << " @ Location: " << res << std::endl;
    return (1);
}