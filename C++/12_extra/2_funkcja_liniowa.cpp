#include <iostream>
#include <functional>
#include <complex>

//*******************************************

template<typename T>
class liniowa
{
private:
    T a;
    T b;

public:
    liniowa(T A, T B) : a(A), b(B) {}

    T operator() (T x)
    {
        return std::bind (
            std::plus<T>(),
            std::bind (
                std::multiplies<T>(),
                a,
                std::placeholders::_1
            ),
            b
        )(x);
    }
};

//*******************************************

int main()
{
    liniowa<int> I = liniowa<int>(2, 3);
    liniowa<float> F = liniowa<float>(4.5, 6.8);
    liniowa<double> D = liniowa<double>(3.7, 1.5);
    liniowa<std::complex<double>> C = liniowa<std::complex<double>>(std::complex<double>(2, 3), std::complex<double>(3, 2));

    std::cout<< "INT: " << I(3) << "\n";
    std::cout<< "FLOAT: " << F(2) << "\n";
    std::cout<< "DOUBLE: " << D(1) << "\n";
    std::cout<< "COMPLEX: " << C(1) << "\n";
}
