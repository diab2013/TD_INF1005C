// Ex_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cout << "Entrer les coordonnées en X des trois points : ";
	float pointX1 = 0, pointX2 = 0, pointX3 = 0;
	cin >> pointX1 >> pointX2 >> pointX3;

	cout << "Entrer les coordonnées en Y des trois points : ";
	float pointY1 = 0, pointY2 = 0, pointY3 = 0;
	cin >> pointY1 >> pointY2 >> pointY3;

	float coordX = (pointX1 + pointX2 + pointX3) / 3;
	float coordY = (pointY1 + pointY2 + pointY3) / 3;

	cout << "Les coordonnees du centre de gravite du triangles sont (" << coordX << ";" << coordY << ").";
}