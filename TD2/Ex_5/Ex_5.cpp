// Ex_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string article;
	int prix, argent_a_rendre, entree, resultat, nb_billets;

	cout << "Entrer le nom de votre article : ";
	cin >> article;
	cout << "Entrer le prix de votre article : ";
	cin >> prix;
	cout << "Entrer le montant d'argent donnee par le client : ";
	cin >> entree;

	argent_a_rendre = entree - prix;
}