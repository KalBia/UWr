#ifndef _WYJSCIE_
#define _WYJSCIE_
#include <fstream>
#include <iostream>
//*******************************************

class OUT
{
    std::ofstream os;

public:
    OUT(std::string slowo)
    {
        os.open(slowo, std::ios::binary);
        os.exceptions(std::ios::failbit | std::ios::badbit);
    }

    template <typename T>
    T Write(T arg)
    {
        os.write(reinterpret_cast<char*>(&arg), sizeof(arg));
        return arg;
    }

    ~OUT()
    {
        os.close();
    }
};

//*******************************************
#endif
