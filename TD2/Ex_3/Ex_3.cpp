// Ex_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
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
	strChaineSplit = strChaine.substr(intSplit);
	cout << strChaineSplit;
}