#pragma once
#include <iostream>
class Kredyt {
public:
	Kredyt(double a, int b) :dlug{ a }, pozostale_raty{b} {
		if (pozostale_raty > 9) {
			odsetki = 0.25;
		}
		else if (6 < pozostale_raty &&  pozostale_raty< 9) {
			odsetki = 0.15;
		}
		else {
			odsetki = 0.1;
		}
		rata = (dlug * odsetki) / pozostale_raty; }
	~Kredyt() {}
	double splac_rate() {	
		if(dlug>=0)
			dlug -= rata;
			pozostale_raty--;
			return rata;
		
	};
private:
	double dlug;
	int pozostale_raty;
	double odsetki;
	double rata;
};