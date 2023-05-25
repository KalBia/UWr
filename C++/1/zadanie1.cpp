#include <iostream>
#include <string>
#include <vector>
using namespace std;

//*******************************************

const vector<pair<int, string>> rzym = 
{
{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, 
{9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
};

//*******************************************

bool convertable (string s)
{
    for (char c: s)
    {
        if (c < '0' || c > '9')
            return false;
    }
    return true;
}

bool in_range(int x)
{
    if (x < 1 || x > 3999)
        return false;
    return true;
}

string bin2rzym (int x)
{
    string result = "";
    int rome_id;
    while (x > 0)
    {
        rome_id = 0;
        while (x < rzym[rome_id].first)
            rome_id++;
        
        result += rzym[rome_id].second;
        x -= rzym[rome_id].first;
    }

    return result;
}

//*******************************************

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        string s = argv[i];

        if (!convertable(s))
        {
            clog << "Invalid argument\n";
            continue;
        }

        int x = stoi(s);

        if (!in_range(x))
        {
            clog << "Argument not in range\n";
            continue;
        }

        cout<< bin2rzym(x) << "\n";
    }
}