#ifndef Vektor_H
#define Vektor_H

#include <iostream>
#include <cmath>
#include <iomanip>

extern const double pi;

class Vektor
{
private:
	double x;
    double y;
    double z;
public:
	Vektor(double x, double y, double z);
	~Vektor();

	void ausgabe() const;
	Vektor sub(const Vektor& input) const;
	double laenge() const;
	double skalarProd(const Vektor& input) const;
	double winkel(const Vektor& input) const;
	void rotiereUmZ(const double rad);

};

#endif
