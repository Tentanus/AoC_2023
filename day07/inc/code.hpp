#ifndef CODE_HPP
# define CODE_HPP

#include <fstream>
#include <iostream>

#include <unordered_map>

enum class HV
{
	HIGH,				// 5
	PAIR,				// 4
	TWOPAIR,			// 3
	THREEOFAKIND,		// 3
	FULLHOUSE,			// 2
	FOUROFAKIND,		// 2
	FIVEOFAKIND			// 1
};

HV getHandValue(const std::string hand)
{
	std::unordered_map<char, int> map;
	for (size_t i = 0; i < hand.length(); i++)
		map[hand.at(i)]++;

	if (map.size() == 1)
		return (HV::FIVEOFAKIND);
	if (map.size() == 5)
		return (HV::HIGH);
	if (map.size() == 4)
		return (HV::PAIR);
	if (map.size() == 3 )
	{
		for (auto it : map)
			if (it.second == 3)
				return (HV::THREEOFAKIND);
		return(HV::TWOPAIR);
	}
	if (map.size() == 2 )
		for (auto it : map)
			if (it.second == 3)
				return (HV::FULLHOUSE);	
	return (HV::FOUROFAKIND);
}

size_t getCardValue(const char letter)
{
	switch (letter)
	{
	case '2':
		return (1);
	case '3':
		return (2);
	case '4':
		return (3);
	case '5':
		return (4);
	case '6':
		return (5);
	case '7':
		return (6);
	case '8':
		return (7);
	case '9':
		return (8);
	case 'T':
		return (9);
	case 'J':
		return (10);
	case 'Q':
		return (11);
	case 'K':
		return (12);
	case 'A':
		return (13);
	}
    std::cout << "REACHED END OF getCardValue";
	return (SIZE_MAX);
}

std::string showVal(HV val)
{
	switch (val)
	{
	case HV::HIGH:
		return ("NONE");
	case HV::PAIR:
		return ("PAIR");
	case HV::TWOPAIR:
		return ("TWO PAIR");
	case HV::THREEOFAKIND:
		return ("THREE OF A KIND");
	case HV::FULLHOUSE:
		return ("FULL HOUSE");
	case HV::FOUROFAKIND:
		return ("FOUR OF A KIND");
	case HV::FIVEOFAKIND:
		return ("FIVE OF A KIND");
	default:
		return ("FAULTY INPUT (showVal)");
	}
}

class CamelHand
{
	public:
	std::string _cards;
	std::string _bid;
	HV _value;

	CamelHand(std::string line) {
		size_t i = line.find_first_of(" ");
		_cards = line.substr(0, i);
		_bid = line.substr(i + 1);

		_value = getHandValue(_cards);

        std::cout << "CamelHand:\t" << _cards << " val: "  << showVal(_value) << std::endl;
	}
};

#endif