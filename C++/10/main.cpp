#include "in.hpp"
#include "out.hpp"
#include <vector>
#include <algorithm>
//*******************************************

std::vector<std::string> read_lines_to_vector(std::vector<std::string> &test)
{
    std::string temp;
    std::getline(std::cin, temp);
    while (temp != "end")
    {
        test.push_back(temp);
        std::getline(std::cin, temp);
    }

    test.erase(test.begin());
    std::vector<std::string> sorted = test;
    std::sort(sorted.begin(), sorted.end());

    return sorted;
}

//*******************************************

int get_index(std::vector<std::string> v, std::string linia)
{
    auto it = find(v.begin(), v.end(), linia);

    if (it != v.end())
    {
        int index = it - v.begin();
        return index;
    }
    else
    {
        return -1;
    }
}

//*******************************************

void write_lines_from_vector(std::vector<std::string> sorted, std::vector<std::string> test)
{
    int licznik = 0;
    while (licznik < sorted.size())
    {
        std::cout<< index(get_index(test, sorted[licznik]), 4) << colon << sorted[licznik] << std::endl;

        licznik++;
    }
}

//*******************************************

int main()
{
    std::cout<< "CLEARLINE\n";
    std::string wejscie0;
    std::cin>> clearline >> wejscie0;
    std::cout<< wejscie0 << "\n\n";

    std::cout<< "IGNORE (3)\n";
    std::string wejscie1;
    std::cin>> myignore(3) >> wejscie1;
    std::cout<< wejscie1 << "\n\n";

    std::cout<< "COMMA\n";
    int a = 2, b = 3;
    std::cout<< a << comma << 3;
    std::cout<< "\n\n";

    std::cout<< "COLON\n";
    std::cout<< a << colon << 3;
    std::cout<< "\n\n";

    std::cout<< "INDEX\n";
    std::vector<std::string> test;
    std::vector<std::string> sorted = read_lines_to_vector(test);
    write_lines_from_vector(sorted, test);
    std::cout<< "\n\n";
}
