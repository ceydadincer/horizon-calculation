#include "Vektor.h"
#include <cmath>
#include <iomanip>

const double pi = M_PI;

/**
 * @brief Konstruktor, der ein neuer Vektor mit x, y und z Komponenten erstellt
 *
 * @param inX eine Gleitkommazahl
 * @param inY eine Gleitkommazahl
 * @param inZ eine Gleitkommazahl
 */
Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ) {}

/**
 * @brief Destruktor, der von der Klasse benutzten Ressourcen bei der Zerstoerung einer Instanz freigibt.
 */
Vektor::~Vektor() {}

/**
 * @brief Funktion, die die Komponenten des Vektors ausgibt
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << std::fixed << std::setprecision(4) << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}

/**
 * @brief Funktion, die Differenz zwichen zwei Vektoren berechnet
 *
 * @param input eine Referenz auf den von dem haupten Vektor subtrahierten Vektor
 *
 * @return der gerechnete Vektor (ein Objekt der Klasse Vektor)
 */
Vektor Vektor::sub(const Vektor& input) const
{
	double x_neu = x - input.x;
	double y_neu = y - input.y;
	double z_neu = z - input.z;

	Vektor vector(x_neu, y_neu, z_neu);
	return vector;
}

/**
 * @brief Funktion, die Laenge eines Vektors berechnet
 *
 * @return das gerechnete Ergebnis (double)
 */
double Vektor::laenge() const
{
	return pow((x*x + y*y + z*z), 0.5);
}

/**
 * @brief Funktion, die das Skalarprodukt zweier Vektoren berechnet
 *
 * @param input eine Referenz auf den Vektor, dessen Skalarprodukt von ihm und dem haupten Vektor berechnet wird
 *
 * @return das gerechnete Ergebnis (double)
 */
double Vektor::skalarProd(const Vektor& input) const
{
	return x*input.x + y*input.y + z*input.z;
}

/**
 * @brief Funktion, die den Winkel zwischen zwei Vektoren in Rad berechnet
 *
 * @param input eine Referenz auf den Vektor, dessen Winkel zwischen ihm und dem haupten Vektor berechnet wird
 *
 * @return das gerechnete Ergebnis (double)
 */
double Vektor::winkel(const Vektor& input) const
{
	return acos(skalarProd(input) / (laenge()*input.laenge())); // ergibt sich rad
}

/**
 * @brief Funktion, die einen Vektor um einen in Rad vorgegebenen Winkel gegen den Uhrzeigersinn dreht
 *
 * @param rad eine ganze Zahl in Rad
 */
void Vektor::rotiereUmZ(const double rad)
{
	double x_neu = x*cos(rad) - y*sin(rad);
	double y_neu = x*sin(rad) + y*cos(rad);

	x = x_neu;
	y = y_neu;
}
