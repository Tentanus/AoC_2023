
// clang-format off
#include <code.hpp>

#define REPORT(X) std::cout << (X)

void addGalaxies(std::string &line, std::vector<Galaxy> &mil, size_t y,
std::vector<bool> &hitx, std::vector<bool> &hity)
{
    size_t x = 0;
    x = line.find("#");
    if (x != std::string::npos)
        hity.push_back(true);
    else
        hity.push_back(false);

    while (x != std::string::npos)
    {
        hitx.at(x) = true;
        mil.push_back(Galaxy(x + 1, y));
        x = line.find("#", x + 1);
    }
}

void printData(std::vector<Galaxy> &milkyway, 
std::vector<bool> &hitmapx, std::vector<bool> &hitmapy)
{
    for (auto galaxy : milkyway)
        std::cout << "[" << galaxy.x << "," << galaxy.y << "]  ";
    
    std::cout << "\nhit X:\t";
    for (bool hit : hitmapx)
        std::cout << (hit ? "1" : "0") << " ";
    std::cout << std::endl;

    std::cout << "hit Y:\t";
    for (bool hit : hitmapy)
        std::cout << (hit ? "1" : "0") << " ";
    std::cout << std::endl;
}

void AdjustCordinates(std::vector<Galaxy> &milkyway, 
std::vector<bool> &hitmapx, std::vector<bool> &hitmapy)
{
    (void) hitmapy;
    int distx[hitmapx.size()];
    int disty[hitmapy.size()];
    int fact = 0;
    
    for (size_t i = 0; i < hitmapx.size() ; i++)
    {
        if (hitmapx.at(i) == false)
            fact++;
        distx[i] = fact;
    }
    fact = 0;
    for (size_t i = 0; i < hitmapy.size() ; i++)
    {
        if (hitmapy.at(i) == false)
            fact++;
        disty[i] = fact;
    }
    for (Galaxy &gal : milkyway)
    {
        int x = gal.x;
        gal.x += distx[x - 1];
        int y = gal.y;
        gal.y += disty[y - 1];
    }
}

size_t addDiff(const std::vector<Galaxy> &milkyway)
{
    size_t ret = 0;

    for (const Galaxy &gal : gal)
    {
        for ()
    }
}

int main(int argc, char* argv[])
{
    std::string file = "xinput.txt";
    if (argc != 1)
        file = argv[1];
        
    std::ifstream infile(file);
    std::string line;

    std::vector<Galaxy> milkyway;
    std::vector<bool> hitmapx;
    std::vector<bool> hitmapy;

    size_t liney = 1;
    while (std::getline(infile, line))
    {
        if (liney == 1)
        {
            size_t i = line.length();
            while (i--)
                hitmapx.push_back(false);
        }
        #ifdef DEBUG
            std::cout   << "line:\t\t" << line << "\n";
        #endif
        
        addGalaxies(line, milkyway, liney, hitmapx, hitmapy); 
        liney++;
    }

    printData(milkyway, hitmapx, hitmapy);
    AdjustCordinates(milkyway, hitmapx, hitmapy);
    size_t res = addDiff(milkyway);

    REPORT("Result:\t") << res << std::endl;
    return (0);
}
// clang-format on
