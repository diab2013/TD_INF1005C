// Ex_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, k;
	double resultat = 1.0;
	cout << "Entrer une valeur de n: ";
	cin >> n;
	cout << "E ntrer une valeur de k (inferieur a n): ";
	cin >> k;
	while (k > n) {
		cout << "La valeur de k ne peut etre plus grande que n!" << endl;
		cout << "Entrer une valeur de k (inferieur a n): ";
		cin >> k;
	}
	cout << "resultat = " << resultat << endl;
	if (k != n) {
		while (k < n) {

			double result = ((k + 1) / (n - k));
			cout << "result = " << result << endl;
			resultat = resultat * result;
			cout << "resultat = " << resultat << endl;
			k++;
		}
	}
	cout << "Le resultat est " << resultat;
}