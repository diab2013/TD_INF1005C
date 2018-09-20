/**
* Programme qui coupe une chaine en deux
* \file   Ex_3.cpp
* \author Diab et Abdelrahman
* \date   23 septembre 2018
* Créé le 12 septembre 2018
*/

#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	cout << "Entrer une chaine quelconque : ";
	string strChaine;
	getline(cin, strChaine);
	cout << "Entrer un entier pour separer la chaine (plus petit que taille chaine) : ";
	string strChaineSplit;
	int intSplit;
	cin >> intSplit;
	if (intSplit > strChaine.length()) {
		cout << "L'entier ne peut etre plus grand que la longueur de la chaine.";
		return 1;
	}
	strChaineSplit = strChaine.substr(intSplit);
	cout << strChaineSplit << endl;
	strChaineSplit = strChaine.substr(0, intSplit);
	strChaineSplit[0] = toupper(strChaineSplit[0]);
	cout << setw(strChaine.length()) << strChaineSplit;
}