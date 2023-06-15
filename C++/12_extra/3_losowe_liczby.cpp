#include <iostream>
#include <functional>
#include <array>
#include <vector>
#include <algorithm>
#include <ctime>

//*******************************************

template<int Dogr, int Gogr>
auto losowyInt = [] ()
{
    static bool on = false;

    if (!on)
    {
        srand((unsigned int)std::time(nullptr));
        on = true;
    }

    return Dogr + (rand() % (Gogr - Dogr + 1));
};

//*******************************************

int main()
{
    const int N = 15;

    int tab[N];
    std::generate_n(tab, N, losowyInt<1, 15>);

    std::array<int, N> arr;
    std::generate_n(arr.begin(), N, losowyInt<5, 20>);

    std::vector<int> vec(N);
    std::generate_n(vec.begin(), N, losowyInt<15, 35>);

    std::cout<< "TEST 1:\n";
    std::cout<< "   TAB\n";
    std::for_each(tab, tab+N, [](int x){std::cout<< x << " ";});
    std::cout<< "\n";
    std::cout<< "   ARRAY\n";
    std::for_each(arr.begin(), arr.end(), [](int x){std::cout<< x << " ";});
    std::cout<< "\n";
    std::cout<< "   VECTOR\n";
    std::for_each(vec.begin(), vec.end(), [](int x){std::cout<< x << " ";});
    std::cout<< "\n";

    //*******************************************

    std::array<int, 3*N> prime;
    auto it = prime.begin();
    auto is_prime = [&it] (int x)
    {
        if (x != 2 && x % 2 == 0)
            return false;

        int i = 3;
        while (i*i <= x)
        {
            if (x != i && x % i == 0)
                return false;
            i += 2;
        }

        it++;
        return true;
    };

    std::copy_if(tab, tab+N, it, is_prime);
    std::copy_if(arr.begin(), arr.end(), it, is_prime);
    std::copy_if(vec.begin(), vec.end(), it, is_prime);

    std::cout<< "\nTEST 2:\n";
    std::for_each(prime.begin(), it, [](int x){std::cout<< x << " ";});
}
