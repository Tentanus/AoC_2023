#ifndef CODE_HPP
# define CODE_HPP

#include <fstream>
#include <vector>
#include <iostream>

class Galaxy
{
	public:
	size_t x;
	size_t y;
	
	Galaxy(size_t xpos, size_t ypos) : x(xpos), y(ypos) {};
} ;

std::ostream &operator<<(std::ostream &out, const Galaxy &gal)
{
	std::cout << "[" << gal.x << "," << gal.y << "]";
	return (out);
}

#endif