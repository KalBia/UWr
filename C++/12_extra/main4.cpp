#include "4_trojkat.hpp"
#include <vector>
#include <algorithm>
#include <array>

//*******************************************

int main()
{
    std::vector<trojkat> vec;
    vec.push_back( trojkat{2, 3, 3} );
    vec.push_back( trojkat{5, 3, 7} );
    vec.push_back( trojkat{12, 13, 3} );
    vec.push_back( trojkat() );
    vec.push_back( trojkat{4, 5, 3} );
    vec.push_back( trojkat{13, 6, 8} );
    vec.push_back( trojkat{5, 5, 5} );
    vec.push_back( trojkat{23, 15, 12} );
    vec.push_back( trojkat{30, 15, 16} );
    vec.push_back( trojkat{2, 3, 4} );
    vec.push_back( trojkat{11, 5, 9} );
    vec.push_back( trojkat{4, 4, 6} );
    vec.push_back( trojkat{2, 3, 3} );

    std::vector<trojkat> vec_sorted = vec;
    std::sort( vec_sorted.begin(), vec_sorted.end(), [](const trojkat& a, const trojkat& b){return a.obwod() <= b.obwod();});
    std::cout<< "\nPOSORTOWANE\n";
    std::for_each(vec_sorted.begin(), vec_sorted.end(), [](const trojkat& a){std::cout<< a << "\n";});

    std::cout<< "\nMIN ELEMENT\n";
    std::cout<< *std::min_element(vec.begin(), vec.end(), [](const trojkat& a, const trojkat& b){return a.pole() <= b.pole();});

    std::cout<< "\nMAX ELEMENT\n";
    std::cout<< *std::max_element(vec.begin(), vec.end(), [](const trojkat& a, const trojkat& b){return a.pole() <= b.pole();});

    std::array<trojkat, 13> ostre;
    auto it = ostre.begin();
    auto lambda = [&it](const trojkat& a)
    {
        double bok1K = a.getbok1() * a.getbok1();
        double bok2K = a.getbok2() * a.getbok2();
        double bok3K = a.getbok3() * a.getbok3();

        if (bok1K + bok2K <= bok3K || bok1K + bok3K <= bok2K || bok2K + bok3K <= bok1K)
            return false;

        it++;
        return true;
    };
    std::copy_if(vec.begin(), vec.end(), ostre.begin(), lambda);
    std::cout<< "\nOSTROKATNE\n";
    std::for_each(ostre.begin(), it, [](const trojkat& a){std::cout<< a << "\n";});
}
