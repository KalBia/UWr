#include <iostream>
#include "klasa_liczba.hpp"

int main()
{
    liczba Domyslne = liczba();
    liczba ZadanaWart(17);
    liczba Skopiowane(ZadanaWart);
    
    std::cout<< "\nKONSTRUKTOR DOMYSLNY:\n";
    std::cout<< Domyslne.getValue() << std::endl;

    std::cout<< "\nKONSTRUKTOR Z ZADANA WARTOSCIA:\n";
    std::cout<< ZadanaWart.getValue() << std::endl;

    std::cout<< "\nKONSTRUKTOR KOPIUJACY:\n";
    std::cout<< Skopiowane.getValue() << std::endl;

    std::cout<< "\nSETVALUE:\n";
    ZadanaWart.setValue(42); // hist = 17, 42 [17, 42, -]
    std::cout<< ZadanaWart.getValue() << std::endl;
    ZadanaWart.setValue(5); // hist = 17, 42, 5 [17, 42, 5]
    std::cout<< ZadanaWart.getValue() << std::endl;
    ZadanaWart.setValue(19); // hist = 19, 42, 5 [42, 5, 19]
    std::cout<< ZadanaWart.getValue() << std::endl;
    ZadanaWart.setValue(13); // hist = 19, 13, 5 [5, 19, 13]
    std::cout<< ZadanaWart.getValue() << std::endl;

    std::cout<< "\nREVERT:\n";
    ZadanaWart.revertValue(); // hist = 19, 13, 5 [5, 19, -]
    std::cout<< ZadanaWart.getValue() << std::endl;
    ZadanaWart.revertValue(); // hist = 19, 13, 5 [5, -, -]
    std::cout<< ZadanaWart.getValue() << std::endl;
    ZadanaWart.revertValue(); // hist = 19, 13, 5 [5, -, -]
    std::cout<< ZadanaWart.getValue() << std::endl;
    ZadanaWart.revertValue(); // hist = 19, 13, 5 [5, -, -]
    std::cout<< ZadanaWart.getValue() << std::endl;

    std::cout<< "\nSET po REVERT:\n";
    ZadanaWart.setValue(21);
    std::cout<< ZadanaWart.getValue() << std::endl;
    ZadanaWart.setValue(101);
    std::cout<< ZadanaWart.getValue() << std::endl;

    std::cout<< "\nKONSTRUKTOR PRZENOSZACY:\n";
    liczba Przenoszacy = std::move(ZadanaWart);
    std::cout<< "Przeniesiony do: " << Przenoszacy.getValue() << std::endl;
    std::cout<< "Przeniesiony z: " << ZadanaWart.getValue() << std::endl;

}