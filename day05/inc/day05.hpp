#ifndef DAY05_HPP
# define DAY05_HPP

#include <fstream>
#include <iostream>

#include <vector>

class mute
{

	public:
		long long _src;
		long long _dst;
		long long _range;

	mute(std::string line) {
		size_t start = 0;
		size_t end = line.find(" ", start);
		_dst = std::stoll(line.substr(start, end));

		start = end;
		end = line.find(" ", start + 1);
		_src = std::stoll(line.substr(start, end));

		start = end;
		end = line.find(" ", start + 1);
		_range = std::stoll(line.substr(start));

		#ifdef DEBUG
		    std::cout << "new: " << _src << " " << _dst << " " << _range << std::endl;
		#endif
	};
	bool isin_src_range(const long long inp) const {
		return (inp >= _src && inp < _src + _range);
	};
	long long get_dst(const long long inp) const {
//		std::cout<<"case: "<<_dst<<" + ("<<inp<<" - "<<_src<<std::endl;
		return (_dst + (inp - _src));
	};
};


class Almap 
{
	public:
		std::string from;
		std::string to;
		std::vector<mute> mutes;

		Almap(std::string line) {
			size_t start = 0;
			size_t end = line.find("-");	
			from = line.substr(start, end);
			start = end + 4;
			end = line.find(" ", start);
			to = line.substr(start, end - start);

			#ifdef DEBUG
			    std::cout << "\nCreating New Map: " << from << " - " << to << "\n";
			#endif
			};

};


/*

    for (long long seed : seeds)
    {
        long long nbr = seed;
        for (Almap alm : Almanac)
        {
//            std::cout << alm.from << " to " << alm.to << ":\n";
            for (mute mu : alm.mutes)
            {
                if (mu.isin_src_range(nbr))
                {
                    nbr = mu.get_dst(nbr);
                    break;
                }
//                std::cout << mu._src << " " << mu._dst << " " << mu._range << "\n";
            }
        }
        if (nbr < res)
            res = nbr;
    }

*/

#endif