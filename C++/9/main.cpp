#include <iostream>
#include "list.hpp"
#include "kolejka.hpp"
#include "stos.hpp"
#include "sort.hpp"

int main()
{
    calc::lista<int>* L = new calc::lista<int>();
    std::cout<< "START - LISTA\n\n";
    std::cout<< "czy puste?\n" << L->is_empty() << std::endl;
    std::cout<< "dlugosc?\n" << L->length() << std::endl;
    std::cout<< "L:\n" << *L << std::endl;

    L->push_back(17); // [17]
    std::cout<< "L + 17:\n" << *L << std::endl;
    L->push_back(42); // [17, 42]
    std::cout<< "L + 42:\n" << *L << std::endl;
    L->push_front(63); // [63, 17, 42]
    std::cout<< "63 + L:\n" << *L << std::endl;
    L->push_front(113); // [113, 63, 17, 42]
    std::cout<< "113 + L:\n" << *L << std::endl;
    L->insert(5, 2); // [113, 63, 5, 17, 42]
    std::cout<< "L.insert(5, 2):\n" << *L << std::endl;

    calc::lista<int>* W = new calc::lista<int>(*L);
    std::cout<< "\nW - konstruktor kopiujacy\n";
    std::cout<< "W:\n" << *W << "\n";

    calc::lista<int>* P = new calc::lista<int>();
    *P = *W;
    std::cout<< "W - przypisanie kopiujace\n";
    std::cout<< "P:\n" << *P << "\n";
    std::cout<< "W:\n" << *W << "\n";

    std::cout<< "Testowanie get_elem, get_front, get_back\n";
    std::cout<< "W[0] - front: " << W->get_front() << "\n";
    std::cout<< "W[4] - back: " << W->get_back() << "\n";
    std::cout<< "W[2]: " << W->get_elem(2) << "\n\n";

    std::cout<< "Testowanie metod pop\n";
    P->pop_position(2);
    std::cout<< "P.pop_position(2):\n" << *P << "\n";
    P->pop_front();
    std::cout<< "P.pop_front:\n" << *P << "\n";
    P->pop_back();
    std::cout<< "P.back:\n" << *P << "\n";

    W->push_back(113);
    W->push_back(113);
    std::cout<< "Testowanie metod pop_value i all_value\n";
    std::cout<< "W przed:\n" << *W << "\n";
    std::cout<< "W.count(113): " << W->count(113) << "\n\n";
    W->pop_value(17);
    std::cout<< "W.pop_value(17):\n" << *W << "\n";
    W->pop_all_value(113);
    std::cout<< "W.pop_all_value(113):\n" << *W << "\n";

    std::cout<< "W.find(113): " << W->find(113) << "\n";
    std::cout<< "W.find(42): " << W->find(42) << "\n\n";

    calc::kolejka<int>* K = new calc::kolejka<int>();
    std::cout<< "START - KOLEJKA\n\n";
    std::cout<< "czy puste?\n" << K->is_empty() << std::endl;
    std::cout<< "dlugosc?\n" << K->length() << std::endl;

    K->push_back(15);
    K->push_back(13);
    std::cout<< "K: [15, 13]\n";
    std::cout<< "K.front: " << K->get_front() << std::endl;
    K->pop_front();
    std::cout<< "K.pop_front\n";
    std::cout<< "K.front: " << K->get_front() << "\n\n";

    calc::stos<int>* S = new calc::stos<int>();
    std::cout<< "START - STOS\n\n";
    std::cout<< "czy puste?\n" << S->is_empty() << std::endl;
    std::cout<< "dlugosc?\n" << S->length() << std::endl;

    S->push_front(15);
    S->push_front(13);
    std::cout<< "S: [13, 15]\n";
    std::cout<< "S.front: " << S->get_front() << std::endl;
    S->pop_front();
    std::cout<< "S.pop_front\n";
    std::cout<< "S.front: " << S->get_front() << "\n\n";

    std::cout<< "START - SORT\n\n";
    std::cout<< "L:\n" << *L << std::endl;
    std::cout<< "L is sorted? " << issorted(*L) << "\n\n";
    sort(*L);
    std::cout<< "L aftes sorting:\n" << *L << "\n";
    std::cout<< "L is sorted? " << issorted(*L) << std::endl;

    delete L, P, W, K, S;
}
