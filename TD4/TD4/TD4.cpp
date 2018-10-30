#include "pch.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstdint>
#include <ctime>
using namespace std;


/////Liste des constantes
using Pixel = uint8_t;
static constexpr unsigned tailleX = 500, tailleY = 500;
/////Liste de Structures
struct Point2d {
	double x, y;
};
struct Intervalle {
	int sup, inf;
};

/////Fonction fournie
inline bool ecrireImage(const Pixel image[tailleY][tailleX], const std::string& nomFichier) {
	ofstream fichier(nomFichier, ios::binary);
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

/////Liste de Fonctions à écrire
int borneDansIntervalle(int valeurBorner, Intervalle intervalle) {
	if (valeurBorner < intervalle.inf) {
		return{ intervalle.inf };
	}
	else if (valeurBorner > intervalle.sup) {
		return{ intervalle.sup };
	}
	else {
		return { valeurBorner };
	}
}

bool estDansIntervalle(int valeurBorner, Intervalle intervalle) {
	bool status = false;
	if (intervalle.inf <= valeurBorner && valeurBorner <= intervalle.sup) {
		status = true;
	}
	return { status };
}

void dessinePoint(Point2d point, int intensite, Pixel image[tailleY][tailleX])
{
	
	if (point.x >= 0 && point.x<= 255 && point.y>= 0 && point.y<=255)
	{
		if (image[(Pixel)point.y][(Pixel)point.y] < intensite)
		{
			image[(Pixel)point.y][(Pixel)point.y] = 0;
		}
		else
		{
			image[(Pixel)point.y][(Pixel)point.y] -= intensite;
		}
	}

	
}

double aleatoireZeroUn() {
	
	
}

int aleatoireSelonDistribution(double probabilitesCumulatives[]) {
	double random;
	random = aleatoireZeroUn();
	if (probabilitesCumulatives[0] > random) {
		return { 0 };
	}
	int valeur;
	for (int i = 1; i < sizeof(probabilitesCumulatives); i++) {
		if (probabilitesCumulatives[i] > random && probabilitesCumulatives[i - 1] <= random) {
			//return { i };
			valeur = i;
		}
	}
	return{ valeur };
}


void tests() {
	/////Test de borneDansIntervalle
	for (int i = -1; i <= 4; i++) {
		Intervalle intervalle;
		intervalle.inf = 1, intervalle.sup = 3;
		cout << borneDansIntervalle(i, intervalle) << setw(2);
	}
	cout << "\n" << endl;

	/////Test de estDansIntervalle
	for (int i = -1; i <= 4; i++) {
		Intervalle intervalle;
		intervalle.inf = 1, intervalle.sup = 3;
		cout << estDansIntervalle(i, intervalle) << setw(2);
	}
	cout << "\n" << endl;

	/////Test de dessinePoint
	Pixel Image[tailleX][tailleY] = {};
	for (int i = 0; i < tailleX; i++) {
		for (int j = 0; j < tailleX; j++) {
			Image[i][j] = 255;
		}
	};

	Point2d point1, point2, point3, point4, point5, point6, point7, point8;
	point1.x = 10, point2.x = 20, point3.x = 30, point4.x = -1, point5.x = 500, point6.x = 1, point7.x = 1, point8.x = 30;
	point1.y = 10, point2.y = 15, point3.y = 20, point4.y = 1, point5.y = 1, point6.y = -1, point7.y = 500, point8.y = 20;
	dessinePoint(point1, 255, Image);
	dessinePoint(point2, 100, Image);
	dessinePoint(point3, 128, Image);
	dessinePoint(point4, 255, Image);
	dessinePoint(point5, 255, Image);
	dessinePoint(point6, 255, Image);
	dessinePoint(point7, 255, Image);
	dessinePoint(point8, 128, Image);
	ecrireImage(Image, "imageTestFinal.bmp");

	/////Test de Aleatoire Selon Distribution
	int counter1 = 0;
	for (int i = 0; i < 1000; i++) {
		double probabilite[3] = { 0.1, 0.35, 1.0 };
		if (aleatoireSelonDistribution(probabilite) == 1) {
			counter1++;
		}
	}
	cout << "counter1 = " << counter1 << endl;

}

int main()
{

	tests();
	cout << aleatoireZeroUn();
}