#include <day05-2.hpp>

#include <sstream>
#include <vector>

#define REPORT(X) std::cout << (X)

int main(int argc, char *argv[]) {
  std::string file = "xinput.txt";
  if (argc != 1)
    file = argv[1];

  std::ifstream infile(file);
  std::string line;

  std::getline(infile, line);

  seedlist list(line.substr(7, line.length() - 7));

  std::vector<Almap> Almanac;

  std::getline(infile, line);
  std::getline(infile, line);
  Almap almap(line);

  while (std::getline(infile, line)) {
    if (line.empty()) {
      Almanac.insert(Almanac.begin(), almap);
      std::getline(infile, line);
      almap = Almap(line);
      continue;
    }

    mute mapmute(line);
    almap.mutes.insert(almap.mutes.begin(), mapmute);
  }

  Almanac.insert(Almanac.begin(), almap);

  for (long long i = 0; i < __LONG_LONG_MAX__; i += 100) {
    long long nbr = i;
    for (Almap alm : Almanac) {
      for (mute mu : alm.mutes) {
        if (mu.isin_dst_range(nbr)) {
          nbr = mu.get_src(nbr);
          break;
        }
      }
    }

    if (list.possibleseed(nbr)) {
      REPORT(" !NEW LOW! ") << nbr;
      break;
    }
    REPORT(std::endl);
  }

  return (0);
}
