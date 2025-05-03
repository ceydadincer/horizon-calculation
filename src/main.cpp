//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 04: Einfuehrung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

const double pi = M_PI;

int main()
{
	Vektor vector1(3,4,0);
	Vektor vector2(1,2,0);

	// Testen der Funktionen
	/* double rad = pi/2;

	Vektor vector1_s = vector1.sub(vector2); // vector1 - vector2
	Vektor vector2_s = vector2.sub(vector1); // vector2 - vector1

	vector1_s.ausgabe();
	vector2_s.ausgabe();

	double vector1_l = vector1.laenge();
	double vector2_l = vector2.laenge();

	std::cout << vector1_l << std::endl;
	std::cout << vector2_l << std::endl;

	double vector1_sk = vector1.skalarProd(vector2);
	double vector2_sk = vector2.skalarProd(vector1);

	std::cout << vector1_sk << std::endl;
	std::cout << vector2_sk << std::endl;

	double vector1_w = vector1.winkel(vector2);
	double vector2_w = vector1.winkel(vector1);

	std::cout << vector1_w << std::endl;
	std::cout << vector2_w << std::endl;

	vector1.rotiereUmZ(rad);
	vector2.rotiereUmZ(rad);

	vector1.ausgabe();
	vector2.ausgabe(); */


    double erde_radius = 6371; // der Radius der Erde in km
    double mensch_hoehe = 0.0017; // die Hoehe des Menschs in km
    double platt_hoehe = 0.5557; // die Hoehe des Plattforms in km
    double epsilon = 0.00000001;


	const Vektor Mensch(0, erde_radius+mensch_hoehe+platt_hoehe, 0); // bleibt unveraendert
	Vektor Erde(0, erde_radius, 0); // wird im Uhrzeigersinn gedreht
	Vektor Sicht = Erde.sub(Mensch); // wird immer aktualisiert


	/*  1 |\  3 (think of it as a straight line between the ends of the vectors 1 and 2)
	      | \
	      |  \
	      |   / 2 (dreht im Uhrzeigersinn (von y-Achse zur x-Achse))
	      |  /
	      | /
	      |/
	 (0,0) \
	 	 	\
	         \ 4 (think of it as the same vector as 3 but it starts from the origin)

	 1 -> Mensch, 2 -> Erde, 3 -> der Vektor zwischen Erde und Mensch (Sicht+Mensch), 4 -> Sicht

	 2 hat die Laenge von erde_radius. Am Anfang steht er auf der y-Achse.
	 Wir muessen ihn im Uhrzeigersinn drehen, bis er senkrecht zu 3 steht,
	 also wenn das Skalarprodukt von 2 und 3 null ist.

	 4 berechnen wir mit Erde - Mensch. Er hat die gleiche Richtung und gleiche Laenge
	 wie 3. Das bedeutet, wenn 2 senkrecht zu 3 steht, steht er gleichzeitig senkrecht zu 4.
	 Also das Skalarprodukt von 2 und 4 ist null.

	 Zusammenfassend muessen wir ein Programm implementieren, das Erde langsam rotiert,
	 bis er senkrecht zu Sicht steht. (0.00000001 rad pro Iteration)

	 Am Anfang ist der Winkel zwischen 2 und 4 180 Grad und geht auf 90.
	 Waehrend dessen geht das Skalarprodukt von negativ endlich auf 0 */

	Mensch.ausgabe();
	Erde.ausgabe();
	Sicht.ausgabe();

	long long int schritte = 0;

	while (Erde.skalarProd(Sicht) < 0)
	{
		Erde.rotiereUmZ(-epsilon); // negativ, weil rotiereUmZ die Vektoren gegen den Uhrzeigersinn dreht
		Sicht = Erde.sub(Mensch); // Sicht wird aktualisiert
		schritte++;
	}

	double beta = Erde.winkel(Mensch)*180/pi; // in Grad (0-180)
	double sichtweise = Sicht.laenge();

	std::cout << std::fixed << std::setprecision(12);
	// 12 Nachkommastellen sind sichtbar

	std::cout << "Sie koennen " << sichtweise <<" km weit sehen." << std::endl;
	std::cout << "Sie sind " << (mensch_hoehe+platt_hoehe)*1000 << " Meter hoch." << std::endl;
	std::cout << "Der Winkel betraegt " << beta << " Grad." << std::endl;
	std::cout << "Anzahl Schritte: " << schritte << std::endl;

    return 0;

}
