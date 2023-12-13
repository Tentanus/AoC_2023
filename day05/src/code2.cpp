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

  // REPORT("line") << line << std::endl;

  seedlist list(line.substr(7, line.length() - 7));

  std::vector<Almap> Almanac;

  std::getline(infile, line);
  std::getline(infile, line);
  Almap almap(line);

  while (std::getline(infile, line)) {
    if (line.empty()) {
      Almanac.emplace_back(almap);
      std::getline(infile, line);
      almap = Almap(line);
      continue;
    }

    mute mapmute(line);
    almap.mutes.emplace_back(mapmute);
  }
  Almanac.emplace_back(almap);

  long long res = __LONG_LONG_MAX__;
  long long seed_res;

  //    for ( size_t i = 0 ; i < list.seed.size() ; i++)
  //    {
  //        REPORT("seed & range: ") << list.seed.at(i) << " " <<
  //        list.range.at(i) << std::endl;
  //    }

  for (size_t i = 0; i < list.seed.size(); i++) {
    REPORT("NEW SEED RANGE: ") << i << "\n";
    for (long long j = 0; j < list.range[i]; j++) {
      REPORT("seed: ") << list.seed[i] + j;

      long long nbr = list.seed[i] + j;
      for (Almap alm : Almanac) {
        for (mute mu : alm.mutes) {
          if (mu.isin_src_range(nbr)) {
            nbr = mu.get_dst(nbr);
            break;
          }
        }
        REPORT(" -> ") << nbr;
      }
      if (nbr < res) {
        REPORT(" !NEW LOW!");
        res = nbr;
        seed_res = list.seed[i] + j;
      }
      REPORT(std::endl);
    }
  }

  REPORT("Seed:\t") << seed_res << " @ Location: " << res << std::endl;
  return (1);
}
