// Ex_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double distance, temps, vitesse_initiale, angle;
	double const gravity = 9.8;
	const int X0 = 0;

	cout << "Entrer l'angle et la vitesse en m/s du projectile : ";
	cin >> angle >> vitesse_initiale;
	angle = angle * 0.0174533;

	temps = (2 * vitesse_initiale * sin(angle)) / gravity;
	distance = vitesse_initiale * cos(angle) * temps;

	cout << "La distance maximale parcourure est de " << distance << " metres.";
}