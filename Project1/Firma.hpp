#pragma once
#include "Kredyt.hpp"
#include "Pracownicy.hpp"
#include "RandomNameGenerator.hpp"
#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <string_view>
#include <vector>
using namespace std;
struct Rekruter
{
    unique_ptr< Pracownik > operator()(string b)
    {
        if (b == "Inz")
        {
            return make_unique< Inzynier >(get_random_name(), get_random_wydzial());
        }
        else if (b == "Mag")
        {
            return make_unique< Magazynier >(get_random_name(), get_random_bool());
        }
        else if (b == "Mkt")
        {
            return make_unique< Marketer >(get_random_name(), get_random_int());
        }
        else if (b == "Rob")
        {
            return make_unique< Robotnik >(get_random_name(), get_random_double());
        }
        else
        {
            cout << "Nie ma takiego pracownika" << '\n';
        }
    }
};

class Firma
{
public:
    Firma() : n_prac{0}, stan_konta{10}
    {
        zatrudnij("Inz");
        zatrudnij("Mag");
        zatrudnij("Mkt");
        zatrudnij("Rob");
    }
    ~Firma() {}
    void wez_kredyt(double kwota, int raty)
    {
        if (c_zadl <= M * wartosc_firmy())
        {
            unique_ptr< Kredyt > k = make_unique< Kredyt >(kwota, raty);
            n_kredytow++;
            kredyt.emplace_back(move(k));
            stan_konta += kwota;
            c_zadl += kwota;
        }
        else
        {
            cout << "Zbyt duze zadluzenie" << '\n';
        }
    };
    void zatrudnij(string b)
    {
        Rekruter                r;
        unique_ptr< Pracownik > p = r(b);
        wynagrodzenie += p->get_w();
        prac.emplace_back(move(p));
        n_prac++;
    };
    const void drukuj_pracownikow()
    {
        cout << "Lista pracownikow: " << '\n';
        for_each(prac.begin(), prac.end(), [](auto& it) { it->print(); });
    };
    void zaplac_wynagrodzenie() { cout << "Wynagrodzenie pracownikow: " << wynagrodzenie << '\n'; }

    const double get_stan_konta() { return stan_konta; }

    double wartosc_firmy()
    {
        double suma    = 0;
        double wartosc = 0;
        if (historia_przychodow.size() < N)
        {
            for_each(historia_przychodow.begin(), historia_przychodow.end(), [&](auto& it) {
                suma += it;
                wartosc = suma / historia_przychodow.size();
            });
        }
        else
        {
            for (int i = historia_przychodow.size(); i > N; i--)
            {
                suma += historia_przychodow[i];
                wartosc = suma / N;
            }
        }
        return wartosc;
    };
    double splac_raty()
    {
        double raty = 0;
        for_each(kredyt.begin(), kredyt.end(), [&](auto& it) { raty += it->splac_rate(); });
        return raty;
    }

    const double oblicz_przychod()
    {
        int w_p;
        if (CR * CountThis< Robotnik >::get() > CMag * CountThis< Magazynier >::get())
        {
            w_p = CMag * CountThis< Magazynier >::get();
        }
        else
        {
            w_p = CR * CountThis< Robotnik >::get();
        }
        if (w_p > CMkt * CountThis< Marketer >::get())
        {
            w_p = CMkt * CountThis< Marketer >::get();
        }
        int przychod = w_p * CI * CountThis< Inzynier >::get();
        historia_przychodow.emplace_back(przychod);
        return przychod;
    }
    void otrzymaj_przychod()
    {
        double dochod = 0;
        dochod        = oblicz_przychod() - wynagrodzenie - splac_raty();
        stan_konta += dochod;
        cout << "Dochod w tym miesiacu wynosi " << dochod << '\n';
    }

private:
    int                               CI = 3, CMag = 4, CMkt = 5, CR = 3;
    int                               wynagrodzenie = 0;
    double                            stan_konta;
    int                               n_kredytow;
    vector< unique_ptr< Pracownik > > prac;
    vector< unique_ptr< Kredyt > >    kredyt;
    int                               n_prac;
    double                            M      = 2;
    double                            c_zadl = 0;
    int                               N      = 5;
    vector< double >                  historia_przychodow;
};