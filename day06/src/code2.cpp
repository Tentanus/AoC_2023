
#include <algorithm>
#include <cmath>
#include <code.hpp>
#include <utility>
#include <vector>

#define REPORT(X) std::cout << (X)

int main(int argc, char *argv[]) {
  std::string file = "xinput.txt";
  if (argc != 1)
    file = argv[1];

  std::ifstream infile(file);
  std::vector<long long> time;
  std::vector<long long> dist;

  {
    std::string line_time;
    std::string line_dist;

    std::getline(infile, line_time);
    std::getline(infile, line_dist);

#ifdef DEBUG
    std::cout << "time:\t|" << line_time << "\n";
    std::cout << "dist:\t|" << line_dist << "\n";
#endif

    line_time = line_time.substr(9);
    line_dist = line_dist.substr(9);

    std::pair<size_t, size_t> p_time;
    std::pair<size_t, size_t> p_dist;

    p_time.first = line_time.find_first_of("0123456789");
    p_dist.first = line_dist.find_first_of("0123456789");
    p_time.second = line_time.find_first_of(" ", p_time.first);
    p_dist.second = line_dist.find_first_of(" ", p_dist.first);

    while (p_time.first != std::string::npos &&
           p_dist.first != std::string::npos) {

      time.push_back(std::stoll(
          line_time.substr(p_time.first, p_time.second - p_time.first)));
      dist.push_back(std::stoll(
          line_dist.substr(p_dist.first, p_dist.second - p_dist.first)));

      p_time.first = line_time.find_first_of("0123456789", p_time.second);
      p_dist.first = line_dist.find_first_of("0123456789", p_dist.second);
      p_time.second = line_time.find_first_of(" ", p_time.first);
      p_dist.second = line_dist.find_first_of(" ", p_dist.first);
    }
  }

  std::vector<int> arr;

  for (size_t race = 0; race < time.size(); race++) {
    int peaktime = time.at(race) / 2;
    long long racewins = 1;
    int hold;
    
    for (int i = 1;
        dist.at(race) < -(peaktime + i) * ((peaktime + i) - time.at(race));
        i += 1000)
        {
            racewins += 1000;
            hold = i;
        }
    for (int i = hold;
        dist.at(race) < -(peaktime + i) * ((peaktime + i) - time.at(race));
        i++)
            racewins++;


    for (int i = 1;
         dist.at(race) < -(peaktime - i) * ((peaktime - i) - time.at(race));
        i += 1000)
        {
            racewins += 1000;
            hold = i;
        }
    for (int i = hold;
         dist.at(race) < -(peaktime - i) * ((peaktime - i) - time.at(race));
        i++)
            racewins++;

    REPORT("RACE: ") << race << "\tWINS: " << racewins << std::endl;
    arr.push_back(racewins);
  }
  int res = 1;
  for (auto win : arr)
    res *= win;

  REPORT("RESULT: ") << res;
  return (0);
}
