// Ex_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string strChaine;
	char carARemplace, carRemplace;
	cout << "Entrer une chaine de caracteres: ";
	cin >> strChaine;
	cout << "Entrer un caractere a remplacer: ";
	cin >> carARemplace;
	cout << "Entrer le caractere par lequel en remplace: ";
	cin >> carRemplace;
	for (int i = 0; i < strChaine.length(); i++) {
		if (strChaine[i] == carARemplace) {
			strChaine[i] = carRemplace;
		}
	}
	cout << "Le mot est maintenant " << strChaine << endl;
}