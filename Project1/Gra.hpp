#pragma once
#include "Firma.hpp"
#include <iostream>
using namespace std;
class Gra
{
public:
    Gra() : f(unique_ptr< Firma >(new Firma)), stan{true} {}
    ~Gra() {}
    bool get_stan() { return stan; }
    void akcja_gracza()
    {
        string akcja;
        cin >> akcja;
        if (akcja == "lp")
        {
            f->drukuj_pracownikow();
        }
        else if (akcja == "zinz")
        {
            f->zatrudnij("Inz");
        }
        else if (akcja == "zmag")
        {
            f->zatrudnij("Mag");
        }
        else if (akcja == "zmkt")
        {
            f->zatrudnij("Mkt");
        }
        else if (akcja == "zrob")
        {
            f->zatrudnij("Rob");
        }
        else if (akcja == "kred")
        {
            double w_k;
            int    dl_k;
            cout << "Podaj wielkosc kredytu" << '\n';
            cin >> w_k;
            if (w_k < M)
            {
                cout << "Podaj dlugosc czasu splaty" << '\n';
                cin >> dl_k;
                if (dl_k < T)
                {
                    f->wez_kredyt(w_k, dl_k);
                }
                else
                {
                    cout << "Nie mozesz wziac kredytu na tak dlugo" << '\n';
                }
            }
            else
            {
                cout << "Za duzy kredyt" << '\n';
            }
        }
        else if (akcja == "kt")
        {
            tick();
            if (f->get_stan_konta() < 0)
            {
                cout << "Zbankrutowales..." << '\n';
                stan = false;
            }
            if (f->get_stan_konta() > win)
            {
                cout << "Wygrales!!!" << '\n';
                stan = false;
            }
        }
        else
        {
            cout << "Nieznana komenda" << '\n';
        }
    }

private:
    void tick()
    {
        cout << "Wysokosc rat w tym miesiacu wynosi: " << f->splac_raty() << '\n';
        f->zaplac_wynagrodzenie();
        f->otrzymaj_przychod();
        cout << "Wartosc firmy wynosi: " << f->wartosc_firmy() << '\n';
        cout << "Stan konta w tym miesiacu wynosi: " << f->get_stan_konta() << '\n';
    }
    double              M   = 2000;
    int                 T   = 12;
    double              win = 30000;
    bool                stan;
    unique_ptr< Firma > f;
};