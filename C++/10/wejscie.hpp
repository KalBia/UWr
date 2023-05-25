#ifndef _WEJSCIE_
#define _WEJSCIE_
#include <fstream>
#include <iostream>
//*******************************************

class IN
{
    std::ifstream is;

public:
    IN(std::string filename)
    {
        is.open(filename, std::ios::binary);
        is.exceptions(std::ios::failbit | std::ios::badbit);
    }

    template<typename T>
    T Read(T &arg)
    {
        is.read(reinterpret_cast<char*>(&arg), sizeof(arg));
        return arg;
    }

    int peek(void)
    {
        return is.peek();
    }

    ~IN()
    {
        is.close();
    }
};

//*******************************************
#endif
