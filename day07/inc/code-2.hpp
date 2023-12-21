#ifndef CODE_HPP
#define CODE_HPP

#include <fstream>
#include <iostream>

#include <unordered_map>

enum class HV {
  HIGH,         // 5
  PAIR,         // 4
  TWOPAIR,      // 3
  THREEOFAKIND, // 3
  FULLHOUSE,    // 2
  FOUROFAKIND,  // 2
  FIVEOFAKIND   // 1
};

HV getHandValue(const std::string hand) {
  std::cout << " _val: ";
  std::unordered_map<char, int> map;
  for (size_t i = 0; i < hand.length(); i++)
    map[hand.at(i)]++;

  if (map.size() == 1)
    return (HV::FIVEOFAKIND);
  if (map.size() == 5)
    return (HV::HIGH);
  if (map.size() == 4)
    return (HV::PAIR);
  if (map.size() == 3) {
    for (auto it : map)
      if (it.second == 3)
        return (HV::THREEOFAKIND);
    return (HV::TWOPAIR);
  }
  if (map.size() == 2)
    for (auto it : map)
      if (it.second == 3)
        return (HV::FULLHOUSE);
  return (HV::FOUROFAKIND);
}

HV getHandJackValue(const std::string hand) {
  std::cout << " Jval: ";
  if (hand == "JJJJJ")
    return (HV::FIVEOFAKIND);
  std::unordered_map<char, int> map;

  for (size_t i = 0; i < hand.length(); i++) {
    map[hand.at(i)]++;
  }
  unsigned short jacks;
  {
    std::unordered_map<char, int>::iterator it = map.find('J');
    jacks = it->second;
    map.erase(it);
  }

  unsigned short nbr = 0;
  for (const auto it : map) {
    if (nbr < it.second)
      nbr = it.second;
  }

  if (jacks == 1 && map.size() == 2 && nbr != 3)
    return (HV::FULLHOUSE);

  switch (nbr) {
  case 1: {
    switch (jacks) {
    case 1:
      return (HV::PAIR);
    case 2:
      return (HV::THREEOFAKIND);
    case 3:
      return (HV::FOUROFAKIND);
    case 4:
      return (HV::FIVEOFAKIND);
    }
  case 2: {
    switch (jacks) {
    case 1:
      return (HV::THREEOFAKIND);
    case 2:
      return (HV::FOUROFAKIND);
    case 3:
      return (HV::FIVEOFAKIND);
    }
  }
  case 3: {
    switch (jacks) {
    case 1:
      return (HV::FOUROFAKIND);
    case 2:
      return (HV::FIVEOFAKIND);
    }
  }
  case 4: {
    switch (jacks) {
    case 1:
      return (HV::FIVEOFAKIND);
    }
  }
  }
  }
  std::cout << "REACHED END OF getHandJackValue (hand: " << hand << ") ";
  return (HV::HIGH);
}

size_t getCardValue(const char letter) {

  switch (letter) {
  case 'J':
    return (1);
  case '2':
    return (2);
  case '3':
    return (3);
  case '4':
    return (4);
  case '5':
    return (5);
  case '6':
    return (6);
  case '7':
    return (7);
  case '8':
    return (8);
  case '9':
    return (9);
  case 'T':
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

std::string valToString(HV val) {
  switch (val) {
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
    return ("FAULTY INPUT (valToString)");
  }
}

class CamelHand {
public:
  std::string _cards;
  std::string _bid;
  HV _value;

  CamelHand(std::string line) {
    size_t i = line.find_first_of(" ");
    _cards = line.substr(0, i);
    _bid = line.substr(i + 1);

    std::cout << "CamelHand:\t" << _cards;

    if (_cards.find("J") == std::string::npos)
      _value = getHandValue(_cards);
    else
      _value = getHandJackValue(_cards);

    std::cout << valToString(_value) << std::endl;
  }
};

#endif
