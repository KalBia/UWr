#include <iostream>
#include "wymierna.hpp"

//*******************************************

int main()
{
    obliczenia::wymierna jeden_siedem = obliczenia::wymierna(1, 7);
    obliczenia::wymierna dzies_czterna = obliczenia::wymierna(10, 14);
    obliczenia::wymierna domyslny = obliczenia::wymierna();
    obliczenia::wymierna konwertujacy = obliczenia::wymierna(17);
    obliczenia::wymierna ujemna = obliczenia::wymierna(3, -15);
    obliczenia::wymierna kopiujacy = jeden_siedem;
    obliczenia::wymierna przypisanie = obliczenia::wymierna();
    przypisanie = dzies_czterna;
    obliczenia::wymierna big = obliczenia::wymierna(INT_MAX, 7);
    obliczenia::wymierna small = obliczenia::wymierna(INT_MIN, 7);

    std::cout<< "konstruktor domyslny\n0/1: " << domyslny << "\n\n";

    std::cout<< "konstruktor z wartosciami\n1/7: " << jeden_siedem << "\n\n";

    std::cout<< "wrzucanie ujemnosci w licznik\n-3/15: " << ujemna.get_licz() << "/" << ujemna.get_mian() << "\n\n";

    std::cout<< "uproszczanie\n10/14: " << dzies_czterna.get_licz() << "/" << dzies_czterna.get_mian() << "\n";
    std::cout<< "10/14: " << dzies_czterna << "\n\n";

    std::cout<< "konstruktor konwertujacy\n17/1: " << konwertujacy << "\n\n";

    std::cout<< "konstruktor kopiujacy\n1/7: " << kopiujacy << "\n\n";

    std::cout << "przypisanie kopiujace:\n10/14: " << przypisanie << "\n\n";

    std::cout<< "dodawanie\n1/7 + 10/14 = " << jeden_siedem + dzies_czterna << "\n";
    std::cout<< "dodawanie\n1/7 + -3/15 = " << jeden_siedem + ujemna << "\n\n";

    std::cout<< "odejmowanie\n17 - 1/7 = " << konwertujacy - jeden_siedem << "\n\n";
    std::cout<< "odejmowanie\n1/7 - -3/15 = " << jeden_siedem - ujemna << "\n\n";

    std::cout<< "mnozenie\n1/7 * 10/14 = " << jeden_siedem * dzies_czterna << "\n\n";
    std::cout<< "mnozenie\n1/7 * -3/15 = " << jeden_siedem * ujemna << "\n\n";

    std::cout<< "dzielenie\n1/7 / 10/14 = " << jeden_siedem / dzies_czterna << "\n\n";
    std::cout<< "dzielenie\n1/7 / -3/15 = " << jeden_siedem / ujemna << "\n\n";

    std::cout<< "unarny minus\n-1/7 = " << -jeden_siedem << "\n\n";

    std::cout<< "odwrotnosc\n10/14 -> 10/14: " << !dzies_czterna << "\n\n";

    std::cout<< "na double\n1/7: " << (double)jeden_siedem << "\n\n";

    std::cout<< "na int\n10/14: " << (int)dzies_czterna << "\n";
    std::cout<< "na int\n1/7: " << (int)jeden_siedem << "\n\n";

    std::cout<< "Dodanwanie int: " << jeden_siedem + 1 << "\n\n";
    std::cout<< "Dodanwanie int: " << 1 + jeden_siedem  << "\n\n";

    std::cout<< "WYJATKI\n";
    std::cout<< "test0\n";
    obliczenia::wymierna test0 = obliczenia::wymierna(17, 0);
    std::cout<< "test1\n";
    obliczenia::wymierna test1 = big + jeden_siedem;
    std::cout<< "test2\n";
    obliczenia::wymierna test2 = big * dzies_czterna;
    std::cout<< "test2_1\n";
    obliczenia::wymierna test2_1 = big / domyslny;
    std::cout<< "test3\n";
    obliczenia::wymierna test3 = -small;
    std::cout<< "test4\n";
    obliczenia::wymierna test4 = !domyslny;
}

//*******************************************
