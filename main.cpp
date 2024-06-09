#include "libraries/hdd.h"
#include <cmath>

int main()
{
    try
    {
        hdd h = hdd("wdblue", "wd", "21144141", "ssd", 1000, 10, 500 * pow(2, 10), Type::GPT);
        section s1 = section(1, 100);
        section s2 = section("Section 2", 101, 300, "GPT");
        section s3 = section("Section 3", 301, 1000, "MDR");
        h.addSection(s1);
        h.addSection(s2);
        h.addSection(s3);
        h.print();
        h.printSections();
        h.deleteSectionByIndex(1);
        h.printSections();
    }
    catch (std::exception e)
    {
        std::cout << e.what();
    }
}