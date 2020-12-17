#include "Gra.hpp"
#include <iostream>

using namespace std;
int main()
{
    Gra g;
    cout << "Witaj w symulacji przedsiebiorstwa." << '\n'
         << "Twoim zadaniem jest osiagnac dochod wiekszy niz 30 000." << '\n';
    while (g.get_stan())
    {
        cout << "Ruch gracza:" << '\n';
        g.akcja_gracza();
    }
}