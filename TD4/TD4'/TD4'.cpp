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
int a;
bool estDansIntervalle(int valeurABorner, Intervalle intervalle) {
	bool status = false;
	if (valeurABorner >= intervalle.inf && valeurABorner <= intervalle.sup) {
		status = true;
	}
	return { status };
}

/////////////////////// ces fonctions ont été testées et marche/////////////////




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
}

int main()
{
	tests();
}