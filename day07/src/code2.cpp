
#include <code-2.hpp>

#include <array>
#include <vector>

#define REPORT(X) std::cout << (X)

bool checkHandBiggerInst(const CamelHand &inst, const CamelHand &hand) {
  for (size_t letter = 0; letter < inst._cards.length(); letter++) {
    size_t inst_val = getCardValue(inst._cards.at(letter));
    size_t inst_hand = getCardValue(hand._cards.at(letter));
    if (inst_val == inst_hand)
      continue;
    if (inst_val < inst_hand)
      return (true);
    return (false);
  }
  REPORT("REACHED END OF checkInstBiggerHand");
  return (false);
}

void fittedemplace(std::vector<CamelHand> &list, CamelHand &hand) {
  if (list.size() == 0) {
    list.emplace(list.begin(), hand);
    return;
  }
  for (std::vector<CamelHand>::iterator inst = list.begin(); inst < list.end();
       inst++) {
    if (checkHandBiggerInst(*inst, hand))
      continue;
    list.emplace(inst, hand);
    return;
  }
  list.emplace_back(hand);
}

int main(int argc, char *argv[]) {
  std::string file = "xinput.txt";
  if (argc != 1)
    file = argv[1];

  std::array<std::vector<CamelHand>, 7> handlist;

  std::ifstream infile(file);
  std::string line;

  size_t res = 0;
  while (std::getline(infile, line)) {
    if (line.empty() || line.find('#') != std::string::npos)
      continue;
    CamelHand hand(line);
    fittedemplace(handlist.at(static_cast<size_t>(hand._value)), hand);
  }

  // PRINTING:
  for (auto vecs : handlist) {
    std::cout << "LIST:\t";
    for (auto inst : vecs)
      std::cout << inst._cards << " ";
    std::cout << "\n" << std::endl;
  }

  // Calculate Result:
  size_t mult = 1;
  for (auto vecs : handlist) {
    std::cout << "\nLIST:\t";
    for (auto inst : vecs) {
      std::cout << inst._bid << " * " << mult << " + ";
      res += (std::stoll(inst._bid) * mult);
      mult++;
    }
  }

  REPORT("\nResult:\t") << res << std::endl;
  return (0);
}
