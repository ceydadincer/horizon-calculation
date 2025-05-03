//
// Praktikum Informatik 1 
// 
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.h
// Inhalt: Headerdatei der Klasse Vektor
//


#ifndef Vektor_H
#define Vektor_H

#include <iostream>
#include <cmath>
#include <iomanip>

// extern const double pi = 3.14159265;

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
