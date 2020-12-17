//
// Created by jgalecki on 13.11.2020.
//

#ifndef P1_CPP_LAB_RANDOMNAMEGENERATOR_HPP
#define P1_CPP_LAB_RANDOMNAMEGENERATOR_HPP

#include <array>
#include <random>
#include <string>
#include <sstream>

struct RandomIntGenerator{
    static std::mt19937 prng;
};

std::mt19937 RandomIntGenerator::prng = std::mt19937{std::random_device{}()};

constexpr std::array first_names{
    "Ann",
    "Andrew",
    "John",
    "Jane",
    "Bob",
    "Alice",
    "Bertram",
    "Monica",
    "Laura",
    "Eric",
    "Richard",
    "Karen",
    "Clara",
    "Rupert",
    "Bruce",
    "Martha",
    "Elizabeth",
    "Corey",
    "Nancy",
    "Joe",
    "Amy",
    "Mike",
};

constexpr std::array last_names{
    "Hendricks",
    "Smith",
    "Gates",
    "Stein",
    "Warren",
    "Booker",
    "Williamson",
    "Walters",
    "Dunn",
    "Swanson",
    "Knope",
    "Haverford",
    "Ludgate",
    "Meagle",
    "Favreau",
    "Vietor",
    "Lovett",
    "Pfeifer",
    "Rhodes",
    "Abrams",
    "McFaul",
    "Stone",
    "Sisley",
    "Hanneman",
};
constexpr std::array wydzial{
    "AiNS",
"Arch",
"Chem",
"EiTI",
"El",
"Fiz",
"GiK",
"IBHiIS",
"ICiP",
"IL",
"Mat",
"Mchtr",
"IP",
"MiNI",
"MEiL",
"SiMR",
"Tr",
"Zaz"};

std::string get_random_name(){
    std::uniform_int_distribution<std::size_t> fnd{0, first_names.size() - 1};
    std::uniform_int_distribution<std::size_t> lnd{0, last_names.size() - 1};
    std::stringstream name;
    name << first_names[fnd(RandomIntGenerator::prng)] << ' ' <<
        last_names[lnd(RandomIntGenerator::prng)];
    return name.str();
}
std::string get_random_wydzial() {
    std::uniform_int_distribution<std::size_t> f{ 0, wydzial.size() - 1 };
   std::stringstream w;
    w << wydzial[f(RandomIntGenerator::prng)];
    return w.str();
}
double get_random_double(){
std::uniform_real_distribution<double> unif(40, 48);
std::default_random_engine re;
return unif(re);}
bool get_random_bool() {
    auto rbg = [d = std::uniform_int_distribution< unsigned short >{ 0, 1 }]() mutable {
        return static_cast<bool>(d(RandomIntGenerator::prng)); };
    return rbg();
}
int get_random_int() {
    std::uniform_int_distribution<int> un(100, 10000);
    std::default_random_engine re;
    return un(re);
}
#endif //P1_CPP_LAB_RANDOMNAMEGENERATOR_HPP
