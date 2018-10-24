// TD4'.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
#include<cmath>

using namespace std;

using Pixel = uint8_t;

static constexpr unsigned tailleX = 500, tailleY = 500;


struct Point2d {
	double x, y;
};
struct Intervalle{
	int inf, sup;
};

int borneDansIntervalle(int valeurABorner, Intervalle intervalle) {
	if (valeurABorner > intervalle.sup) {
		return { intervalle.sup };
	} else if (valeurABorner < intervalle.inf) {
		return { intervalle.inf };
	} else {
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

/////////////////////// ces fonctions ont été testées et marche/////////////////

void dessinePoint(Point2d coord, Pixel intensite, Pixel image[tailleX][tailleY])
{
	Intervalle inter, interInten;
	inter.inf = 0;
	inter.sup = 500;
	interInten.sup = 255;
	interInten.inf = 0;
	bool possiblePoint = estDansIntervalle(coord.x, inter) && estDansIntervalle(coord.y, inter);
	bool possibleIntensite = estDansIntervalle(image[(uint8_t)coord.y][(uint8_t)coord.x] -= intensite, interInten);
	if (possiblePoint && possibleIntensite) {
		image[(uint8_t)coord.y][(uint8_t)coord.x] -= intensite;
	}
	else if (possiblePoint && !possibleIntensite) {
		image[(uint8_t)coord.y][(uint8_t)coord.x] = 0;
	}
	

	

}


void tests()
{
	for (int i = -1; i <= 4; i++)
	{
		Intervalle intervalle;
		intervalle.inf = 1;
		intervalle.sup = 3;
		cout << borneDansIntervalle(i, intervalle) << setw(2);
	}
	cout << endl << endl << endl;

	for (int i = -1; i <= 4; i++)
	{
		Intervalle intervalle;
		intervalle.inf = 1;
		intervalle.sup = 3;
		cout << estDansIntervalle(i, intervalle) << setw(2);
	}

	Pixel image[tailleX][tailleY] = { 255 };

	Point2d coord1, coord2, coord3, coord4, coord5, coord6, coord7, coord8;
	coord1.x = 10;
	coord1.y = 10;
	coord2.x = 20;
	coord2.y = 15;
	coord3.x = 30;
	coord3.y = 20;
	coord4.x = -1;
	coord4.y = 1;
	coord5.x = 500;
	coord5.y = 1;
	coord6.x = 1;
	coord6.y = -1;
	coord7.x = 1;
	coord7.y = 500;
	coord8.x = 30;
	coord8.y = 20;


	dessinePoint(coord1, 255, image);
	dessinePoint(coord2, 15, )


}

int main()
{
	tests();
}