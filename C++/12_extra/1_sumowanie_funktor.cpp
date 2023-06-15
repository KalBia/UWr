#include <iostream>
#include <set>
#include <list>
#include <vector>
#include <algorithm>

//*******************************************

template<typename T>
class sumator
{
private:
    T Sum = 0;
    int Num = 0;

public:
    sumator() : Sum(0), Num(0) {}

    void operator() (T elem)
    {
        Num++;
        Sum += elem;
    }

    T sum() { return Sum; }
    int num() { return Num; }
    double av() { return static_cast<double>(Sum)/Num; }
};

//*******************************************

int main()
{
    std::set<int> testSet = {2, 5, 7, 10, 9, 3, 1}; // Sum = 37, Num = 7, av = 5.2857
    std::list<float> testList = {2.3, 4.6, 1.7}; // Sum = 8.6, Num = 3, av = 2.8(6)
    std::vector<double> testVector = {4.5, 2.8, 4.9, 7.8}; // Sum = 20, Num = 4, av = 5

    std::cout<< "SET<INT>\n";
    sumator<int> TS = std::for_each(testSet.begin(), testSet.end(), sumator<int>());
    std::cout<< "sum: " << TS.sum() << "\n";
    std::cout<< "num: " << TS.num() << "\n";
    std::cout<< "av: " << TS.av() << "\n";
    std::cout<< "\n";

    std::cout<< "LIST<FLOAT>\n";
    sumator<float> LS = std::for_each(testList.begin(), testList.end(), sumator<float>());
    std::cout<< "sum: " << LS.sum() << "\n";
    std::cout<< "num: " << LS.num() << "\n";
    std::cout<< "av: " << LS.av() << "\n";
    std::cout<< "\n";

    std::cout<< "VECTOR<DOUBLE>\n";
    sumator<double> VS = std::for_each(testVector.begin(), testVector.end(), sumator<double>());
    std::cout<< "sum: " << VS.sum() << "\n";
    std::cout<< "num: " << VS.num() << "\n";
    std::cout<< "av: " << VS.av() << "\n";
    std::cout<< "\n";
}
