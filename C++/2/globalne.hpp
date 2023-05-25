#ifndef globalne
#define globalne
#include "klasa_odcinek.hpp"
#include "klasa_punkt.hpp"
#include "klasa_trojkat.hpp"
#include "klasa_prosta.hpp"

//*******************************************

double odleglosc_miedzy_punktami(punkt A, punkt B);

bool czy_odcinki_rownolegle(odcinek A, odcinek B);

bool czy_odcinki_prostopadle(odcinek A, odcinek B);

prosta prosta_zawierajaca_odcinek(odcinek X);

bool czy_trojkaty_rozlaczne(trojkat A, trojkat B);

bool czy_zawiera_sie_trojkaty(trojkat A, trojkat B);

punkt przeciecie_prostych(prosta k, prosta l);

//*******************************************

#endif