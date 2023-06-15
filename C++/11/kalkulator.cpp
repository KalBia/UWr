#include "kalkulator.hpp"

//*******************************************

std::unordered_set<std::string> nazwy_zastrzezone;
std::map<std::string, int> func_match;
std::map<std::string, int> con_match;

//*******************************************

void kalkulator::prep_maps()
{
    nazwy_zastrzezone.insert("exit");
    nazwy_zastrzezone.insert("set");
    nazwy_zastrzezone.insert("clear");
    nazwy_zastrzezone.insert("to");
    nazwy_zastrzezone.insert("print");
    nazwy_zastrzezone.insert("symbol");
    nazwy_zastrzezone.insert("zmienna");
    nazwy_zastrzezone.insert("dodawanie");
    nazwy_zastrzezone.insert("odejmowanie");
    nazwy_zastrzezone.insert("mnozenie");
    nazwy_zastrzezone.insert("dzielenie");
    nazwy_zastrzezone.insert("liczba");
    nazwy_zastrzezone.insert("stala");
    nazwy_zastrzezone.insert("zmienna");
    nazwy_zastrzezone.insert("sin");
    nazwy_zastrzezone.insert("cos");
    nazwy_zastrzezone.insert("atan");
    nazwy_zastrzezone.insert("acot");
    nazwy_zastrzezone.insert("sgn");
    nazwy_zastrzezone.insert("abs");
    nazwy_zastrzezone.insert("ceil");
    nazwy_zastrzezone.insert("floor");
    nazwy_zastrzezone.insert("frac");
    nazwy_zastrzezone.insert("ln");
    nazwy_zastrzezone.insert("exp");
    nazwy_zastrzezone.insert("modulo");
    nazwy_zastrzezone.insert("min");
    nazwy_zastrzezone.insert("max");
    nazwy_zastrzezone.insert("log");
    nazwy_zastrzezone.insert("pow");
    nazwy_zastrzezone.insert("e");
    nazwy_zastrzezone.insert("pi");
    nazwy_zastrzezone.insert("fi");

    func_match.insert({"+", 0});
    func_match.insert({"-", 1});
    func_match.insert({"*", 2});
    func_match.insert({"/", 3});
    func_match.insert({"%", 4});
    func_match.insert({"min", 5});
    func_match.insert({"max", 6});
    func_match.insert({"log", 7});
    func_match.insert({"pow", 8});
    func_match.insert({"abs", 9});
    func_match.insert({"sgn", 10});
    func_match.insert({"floor", 11});
    func_match.insert({"ceil", 12});
    func_match.insert({"frac", 13});
    func_match.insert({"sin", 14});
    func_match.insert({"cos", 15});
    func_match.insert({"atan", 16});
    func_match.insert({"acot", 17});
    func_match.insert({"ln", 18});
    func_match.insert({"exp", 19});

    con_match.insert({"e", 0});
    con_match.insert({"pi", 1});
    con_match.insert({"fi", 1});
}

//*******************************************

void kalkulator::menedzer()
{
    prep_maps();
    bool chwilo_trwaj = true;
    bool czy_sa_zmienne = false;
    std::string czesc = "";
    std::string wejscie = "";
    std::string zm = "";
    int it = 0;
    double wynik;

    while (chwilo_trwaj)
    {
        czesc = "";
        wejscie = "";
        zm = "";
        std::queue<symbol*> pojemnik; // BLAD! CZYSC TO PO KAZDYM OBROCIE PETLI! WYCIEK PAMIECI

        std::cout<< "Podaj komende:\n";
        getline(std::cin, wejscie);
        it = 0;

        while(it != wejscie.length() && wejscie[it] != ' ') // wyciagniecie pierwszego slowa komendy
        {
            czesc += wejscie[it];
            it++;
        }

        try
        {
            if (czesc == "exit")
            {
                chwilo_trwaj = false;
            }
            else if (czesc == "clear")
            {
                sprzatacz();
            }
            else if (czesc == "print")
            {
                it++;
                try
                {
                    if (!parser(wejscie, it, pojemnik))
                    {
                        throw std::invalid_argument("parser");
                    }

                    wynik = evaluator(pojemnik);
                    std::cout<< wynik << "\n";
                }
                catch (std::invalid_argument e)
                {
                    std::clog<< "ERROR: blad parsowania\n";
                    continue;
                }
            }
            else if (czesc == "set")
            {
                it++;
                while(it != wejscie.length() && wejscie[it] != ' ') // wyciagniecie nazwy zmiennej
                {
                    zm += wejscie[it];
                    it++;
                }

                try
                {
                    if (zm.length() > 7)
                    {
                        throw std::invalid_argument("zmienna");
                    }

                    if (nazwy_zastrzezone.find(zm) != nazwy_zastrzezone.end())
                    {
                        throw std::invalid_argument("zmienna");
                    }
                }
                catch (std::invalid_argument e)
                {
                    std::clog<< "ERROR: zla nazwa zmiennej\n";
                    continue;
                }

                it++;
                czesc = "";
                while(it != wejscie.length() && wejscie[it] != ' ') // wyciagniecie "to"
                {
                    czesc += wejscie[it];
                    it++;
                }

                try
                {
                    if (czesc != "to")
                    {
                        throw std::invalid_argument("komenda");
                    }
                }
                catch (std::invalid_argument e)
                {
                    std::clog << "ERROR: zle napisana komenda\n";
                    continue;
                }

                it++;
                try
                {
                    if (!parser(wejscie, it, pojemnik))
                    {
                        throw std::invalid_argument("parser");
                    }

                    wynik = evaluator(pojemnik);
                    opiekun(zm, wynik);
                    std::cout<< wynik << "\n";
                }
                catch (std::invalid_argument e)
                {
                    std::clog<< "ERROR: blad parsowania\n";
                    continue;
                }
            }
            else
            {
                throw std::invalid_argument("zmienna");
            }
        }
        catch (std::invalid_argument e)
        {
            std::clog<< "ERROR: nieznana komenda\n";
        }
    }

    std::cout<< "Zakonczenie dzialania...\n";
}

//*******************************************

void kalkulator::sprzatacz()
{
    zmienna::spis_zmiennych.clear();
}

//*******************************************

void kalkulator::opiekun(std::string nazwa, double wartosc)
{
    if (zmienna::spis_zmiennych.find(nazwa) != zmienna::spis_zmiennych.end())
    {
        zmienna::spis_zmiennych.insert(std::make_pair(nazwa, wartosc));
    }
    else
        zmienna::spis_zmiennych[nazwa] = wartosc;
}

//*******************************************

void kalkulator::func_parser(std::string sexp, int kod, std::queue<kalkulator::symbol*> &pojemnik)
{
    switch(kod)
    {
        case 0:
            pojemnik.push( new dodawanie() );
            break;
        case 1:
            pojemnik.push( new odejmowanie() );
            break;
        case 2:
            pojemnik.push( new mnozenie() );
            break;
        case 3:
            pojemnik.push( new dzielenie() );
            break;
        case 4:
            pojemnik.push( new modulo() );
            break;
        case 5:
            pojemnik.push( new min() );
            break;
        case 6:
            pojemnik.push( new max() );
            break;
        case 7:
            pojemnik.push( new log() );
            break;
        case 8:
            pojemnik.push( new pow() );
            break;
        case 9:
            pojemnik.push( new abs() );
            break;
        case 10:
            pojemnik.push( new sgn() );
            break;
        case 11:
            pojemnik.push( new floor() );
            break;
        case 12:
            pojemnik.push( new ceil() );
            break;
        case 13:
            pojemnik.push( new frac() );
            break;
        case 14:
            pojemnik.push( new sin() );
            break;
        case 15:
            pojemnik.push( new cos() );
            break;
        case 16:
            pojemnik.push( new atan() );
            break;
        case 17:
            pojemnik.push( new acot() );
            break;
        case 18:
            pojemnik.push( new ln() );
            break;
        case 19:
            pojemnik.push( new exp() );
            break;
    }
}

//*******************************************

void kalkulator::con_parser(std::string sexp, int kod, std::queue<kalkulator::symbol*> &pojemnik)
{
    switch(kod)
    {
        case 0:
            pojemnik.push( new e() );
            break;
        case 1:
            pojemnik.push( new pi() );
            break;
        case 2:
            pojemnik.push( new fi() );
            break;
    }
}

//*******************************************

bool kalkulator::czy_liczba (std::string s)
{
    for (char c : s)
    {
        if (c < '0' || c > '9')
            if (c != '.' && c != ',' && c != '-')
                return false;
    }
    return true;
}

//*******************************************

bool kalkulator::parser(std::string wyrazenie, int it, std::queue<symbol*> &pojemnik)
{
    std::string sexp = "";
    wyrazenie += ' '; // zeby dorzucic tez ostatni symbol z wyrazenia bez kombinowania z warunkiem ifa

    while (it != wyrazenie.length())
    {
        if (wyrazenie[it] == ' ')
        {
            if (func_match.find(sexp) != func_match.end()) // dowolna funkcja/operator
            {
                func_parser(sexp, func_match[sexp], pojemnik);
            }
            else if (con_match.find(sexp) != con_match.end()) // stale
            {
                con_parser(sexp, con_match[sexp], pojemnik);
            }
            else if (czy_liczba(sexp)) // liczby
            {
                pojemnik.push( new liczba( std::stod(sexp) ) );
            }
            else // zmienna
            {
                auto zit = zmienna::spis_zmiennych.find(sexp);
                if (zit == zmienna::spis_zmiennych.end())
                {
                    std::clog<< "ERROR: nieznana zmienna\n";
                    return false;
                }

                pojemnik.push( new zmienna(zit->first, zit->second) );
            }

            sexp = "";
        }
        else
        {
            sexp += wyrazenie[it];
        }

        it++;
    }

    return true;
}

//*******************************************

double kalkulator::evaluator(std::queue<symbol*> &wyrazenie)
{
    std::stack<double> stos;
    double wynik;
    bool blad = false;

    while (!wyrazenie.empty() && !blad)
    {
        auto sit = wyrazenie.front();
        wyrazenie.pop();

        try
        {
            sit->eval(stos);
        }
        catch (std::invalid_argument e)
        {
            std::clog<< "ERROR: blad podczas evaluowania\n";
            wynik = 0;
            blad = true;
        }
    }

    if (!blad)
    {
        try
        {
            if (stos.size() != 1)
                throw std::invalid_argument("zmienna");

            wynik = stos.top();
        }
        catch(std::exception& e)
        {
            std::clog<< "ERROR: blad podczas ostatniego kroku evaluowania\n";
            wynik = 0.0;
        }
    }

    return wynik;
}
