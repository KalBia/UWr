#include <iostream>
#include <functional>

//*******************************************

std::function<int (int)> Collatz = [] (int n)
{
    int counter = 1;
    std::cout<< n << " ";
    if (n != 1)
        if (n&1)
            counter += Collatz(3*n + 1);
        else
            counter += Collatz(n/2);
    return counter;
};

//*******************************************

int main()
{
    int N = 1;
    while (N != 0)
    {
        std::cout<< "Podaj liczbe [podaj 0 aby zakonczyc]\n";
        std::cin>> N;

        if (N == 0)
            continue;

        std::cout<< "ciag: ";
        int liczba = Collatz(N);
        std::cout<< "\nliczba elementow w ciagu: " << liczba << "\n";
    }
}
