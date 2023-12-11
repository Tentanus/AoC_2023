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
		_src = std::stoll(line.substr(start, end));

		start = end;
		end = line.find(" ", start + 1);
		_dst = std::stoll(line.substr(start, end));

		start = end;
		end = line.find(" ", start + 1);
		_range = std::stoll(line.substr(start));

//		#ifdef DEBUG
//		    std::cout << "new: " << _src << " " << _dst << " " << _range << std::endl;
//		#endif
	};
	bool isin_src_range(const long long inp) const {
		return (inp >= _src && inp <= _src + _range);
	};
	long long get_dst(const long long inp) const {
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

//			#ifdef DEBUG
//			    std::cout << "\nCreating New Map: " << from << " - " << to << "\n";
//			#endif
			};

};

#endif