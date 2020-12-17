#pragma once
#include "ObjCout.hpp"
#include <algorithm>
#include <functional>
#include <iostream>
#include <random>
#include <string_view>
using namespace std;

class Pracownik
{
public:
    virtual void print() = 0;
    virtual int get_w() = 0;
    Pracownik() : imie{"Anonymous"} {}
    Pracownik(string a) : imie{move(a)} {}
    virtual ~Pracownik() = default;
    string imie;
};

class Inzynier : public Pracownik, CountThis< Inzynier >
{
public:
    void print() override
    {
        cout << "Inzynier/ka " << this->imie << ". Ukonczyl/a: " << wydzial
             << ". Wynagrodzenie wynosi " << w << '\n';
    }
    int get_w() override { return w; }

    Inzynier(string imie_, string wydzial_) : Pracownik{imie_}, wydzial{wydzial_} {}
    int w = 5;

private:
    string wydzial;
};

class Magazynier : public Pracownik, CountThis< Magazynier >
{
public:
    void print() override
    {
        cout << "Magazynier/ka " << this->imie << ". Czy umie prowadzic wozek: " << o_w
             << ". Wynagrodzenie wynosi " << w << '\n';
    }
    int get_w() override { return w; }

    Magazynier(string imie_, bool o_w_) : Pracownik{imie_}, o_w{o_w_} {}
    int w = 4;

private:
    bool o_w;
};
class Robotnik : public Pracownik, CountThis< Robotnik >
{
public:
    void print() override
    {
        cout << "Robotnik/czka " << this->imie << ". Rozmiar buta: " << but
             << ". Wynagrodzenie wynosi " << w << '\n';
    }
    int get_w() override { return w; }

    Robotnik(string imie_, double(but_)) : Pracownik{imie_}, but{but_} {}
    int w = 3;

private:
    double but;
};
class Marketer : public Pracownik, CountThis< Marketer >
{
public:
    void print() override
    {
        cout << "Marketer/ka " << this->imie << ". Liczba folowersow: " << folws
             << ". Wynagrodzenie wynosi " << w << '\n';
    }
    int get_w() override { return w; }

    Marketer(string imie_, int folws_) : Pracownik{imie_}, folws{folws_} {}
    int w = 5;

private:
    int folws;
};