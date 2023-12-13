#include <day05-2.hpp>

#include <vector>
#include <sstream>

#define REPORT(X) std::cout << (X)

int main(int argc, char* argv[])
{
    std::string file = "xinput.txt";
    if (argc != 1)
        file = argv[1];
        
    std::ifstream infile(file);
    std::string line;

    std::getline(infile, line);
    
    //REPORT("line") << line << std::endl;

    seedlist list(line.substr(7, line.length() - 7));

    std::vector<Almap> Almanac;
    
    std::getline(infile,line);
    std::getline(infile, line);
    Almap almap(line);
    
    while (std::getline(infile, line))
    {
        if (line.empty())
        {
            Almanac.insert(Almanac.begin(), almap);
            std::getline(infile, line);
            almap = Almap(line);
            continue;
        }
//        #ifdef DEBUG
//            std::cout << "line:\t" << line << "\n";
//        #endif

        mute mapmute(line);
        almap.mutes.insert(almap.mutes.begin(), mapmute);
    }
    Almanac.insert(Almanac.begin(), almap);
/*
    for (auto almap : Almanac)
    {
        REPORT("MAP:\t")    << almap.to << " - " << almap.from << std::endl;
        for (auto mute : almap.mutes)
        {
            REPORT("MUTES: ")   << mute._dst << " - " << mute._src 
                                << "\t" << mute._range << std::endl;
        }

    }
    REPORT(std::endl);
    */

//    for ( size_t i = 0 ; i < list.seed.size() ; i++)
//    {
//        REPORT("seed & range: ") << list.seed.at(i) << " " << list.range.at(i) << std::endl;
//    }
//
    for (long long i = 0 ; i < __LONG_LONG_MAX__ ; i++)
    {
        long long nbr = i;
        REPORT("LOCATION: ") << i;
        for (Almap alm : Almanac)
        {
            for (mute mu : alm.mutes)
            {
                if (mu.isin_dst_range(nbr))
                {
                    nbr = mu.get_src(nbr);
//                    REPORT(" -> ") << nbr;
                    break;
                }
            }
//            REPORT(" -> ") << nbr;    
        }

        if (list.possibleseed(nbr))
        {
            REPORT(" !NEW LOW! ") << nbr;
            break;
        }
        REPORT(std::endl);    
    }
    return (0);
}