#pragma warning(push, 0)        
//Some includes with unfixable warnings
#pragma warning(pop)
#include "pch.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstdint>
#include <cstdlib>
#include <fstream>
using namespace std;

using Pixel = uint8_t;
static constexpr unsigned tailleX = 500, tailleY = 500;
struct Intervalle {
	int inf, sup;
}; 
struct Point2d {
	double x, y;
};

int borneDansIntervalle(int valeurABorner, Intervalle intervalle) {
	if (valeurABorner > intervalle.sup) {
		return { intervalle.sup };
	}
	else if (valeurABorner < intervalle.inf) {
		return { intervalle.inf };
	}
	else {
		return (valeurABorner);
	}
}

bool estDansIntervalle(int valeurABorner, Intervalle intervalle) {
	bool status = false;
	if (valeurABorner >= intervalle.inf && valeurABorner <= intervalle.sup) {
		status = true;
	}
	return { status };
}

void dessinePoint(Point2d coord, Pixel intensite, Pixel image[tailleY][tailleX]) {
	Intervalle inter, interInten;
	inter.inf = 0;
	inter.sup = 500;
	interInten.sup = 255;
	interInten.inf = 0;
	bool possiblePoint = estDansIntervalle(coord.x, inter) && estDansIntervalle(coord.y, inter);
	bool possibleIntensite = estDansIntervalle(image[(uint8_t)coord.y][(uint8_t)coord.x] -= intensite, interInten);
	if (possiblePoint && possibleIntensite) {
		image[(uint8_t)coord.y][(uint8_t)coord.x] -= intensite;
	} else if (possiblePoint && !possibleIntensite) {
		image[(uint8_t)coord.y][(uint8_t)coord.x] = 0;
	}
}

/*void dessinePoint(double PointX, double PointY, int intensite, uint8_t image[tailleX][tailleY])
{
	struct Point
	{
		double PointX;
		double PointY;
	};

	for (int i = 0; i <= tailleX; i++)
	{
		for (int j = 0; j <= tailleY; j++)
		{
			image[i][j] =


		}


	}

}*/

double aleatoireZeroUn() {
	double min = 0.0, max = 1.0, random;
	random = rand() / (float)RAND_MAX;
	return { random };
}

int aleatoireSelonDistribution(double probabilitesCumulatives[])
{
	return{};
}

void  transformePoint(double PointX, double PointY, double transformation[2][1], double& PointXT, double& PointYT)
{
	PointXT = transformation[0][0] * PointX + transformation[0][1] * PointY + transformation[2][0];
	PointYT = transformation[1][0] * PointX + transformation[1][1] * PointY + transformation[2][1];

}

/*
void calculerImage(string nomFichierEntree, string nomFichierSortie)
{
	ifstream source(nomFichierEntree + ".txt");

	int nbrPtsAleatoire;
	source >> cin.get(nbrPtsAleatoire);


}
*/

void tests(){
	for (int i = -1; i <= 4; i++) {
		Intervalle intervalle;
		intervalle.inf = 1;
		intervalle.sup = 3;
		cout << borneDansIntervalle(i, intervalle) << setw(2);
	}
	cout << endl << endl << endl;

	for (int i = -1; i <= 4; i++) {
		Intervalle intervalle;
		intervalle.inf = 1;
		intervalle.sup = 3;
		cout << estDansIntervalle(i, intervalle) << setw(2);
	}	

	uint8_t image[tailleX][tailleY] = { 255 };
}

inline bool ecrireImage(const Pixel image[tailleY][tailleX], const std::string& nomFichier)
{
	std::ofstream fichier(nomFichier, std::ios::binary);
	if (fichier.fail())
		return false;
	uint32_t tailleImageEnOctets = tailleX * tailleY;
	uint32_t resolutionImage = 72 * 10000 / 254;  // En pixels par mètre.
	static const char nombreMagique[] = { 'B', 'M' };
	uint32_t entete[3 + 10] = {
		0,0,0,
		40,
		tailleX, tailleY,
		0x080001, 0,
		tailleImageEnOctets,
		resolutionImage, resolutionImage
	};
	uint32_t tableCouleur[256];

	entete[2] = sizeof(nombreMagique) + sizeof(entete) + sizeof(tableCouleur);
	entete[0] = entete[2] + tailleImageEnOctets;

	for (unsigned i = 0; i < 256; i++)
		tableCouleur[i] = i * 0x010101;

	fichier.write(nombreMagique, sizeof(nombreMagique));
	fichier.write((char*)entete, sizeof(entete));
	fichier.write((char*)tableCouleur, sizeof(tableCouleur));
	fichier.write((char*)image, tailleImageEnOctets);
	return !fichier.fail();
}


int main()
{
	tests();
}