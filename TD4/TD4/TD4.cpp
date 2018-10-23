// TD4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
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
const int tailleX(255), tailleY(255);
struct Point2d {
	double x, y;
};

double borneDansIntervalle(double ValeurABorner, double BorneInferieure, double BorneSuperieure)
{
	static double intervalle[1][2];
	if (estDansIntervalle(ValeurABorner, BorneInferieure, BorneSuperieure) == 1)
	{
		intervalle[1][1] = BorneInferieure;

		return (intervalle[1][2]);
	}
	else
	{
		if (ValeurABorner < BorneInferieure)
		{
			return (BorneInferieure);
		}
		if (ValeurABorner > BorneSuperieure)
		{
			return (BorneSuperieure);
		}
	}

}

bool estDansIntervalle(double ValeurABorner, double BorneInferieure, double BorneSuperieure)
{
	bool status = false;
	if (ValeurABorner >= BorneInferieure && ValeurABorner <= BorneSuperieure)
	{
		status = true;
	}
	return{ status };
}

void dessinePoint(double PointX, double PointY, int intensite, uint8_t image[tailleX][tailleY])
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

}

double aleatoireZeroUn()
{
	double min = 0.0, max = 1.0, random;

	random = rand() / (float)RAND_MAX;
	return { random
	};
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

void calculerImage(string nomFichierEntree, string nomFichierSortie)
{
	ifstream source(nomFichierEntree + ".txt");

	int nbrPtsAleatoire;
	source >> cin.get(nbrPtsAleatoire);


}

void tests()
{
	double ValeurABorner, BorneInferieure, BorneSuperieure;
	borneDansIntervalle(ValeurABorner, BorneInferieure, BorneSuperieure);

	for (int i = -1; i <= 4; ++i)
	{
		ValeurABorner = i;
		BorneInferieure = -1;
		BorneSuperieure = 3;
		cout << borneDansIntervalle << setw(1);
	}
	for (int i = -1; i <= 4; ++i)
	{
		ValeurABorner = i;
		BorneInferieure = -1;
		BorneSuperieure = 3;
		cout << estDansIntervalle << setw(1);
	}
	uint8_t image[tailleX][tailleY] = { 255 };
	dessinePoint(10, 10, 255);
}

int main()
{
	tests();
	calculerImage();
}

int main()
{

}

inline bool ecrireImage(const Pixel image[tailleY][tailleX], const std::string& nomFichier)
{
	ofstream fichier(nomFichier, std::ios::binary);
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