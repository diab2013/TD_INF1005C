/**
* Programme qui montre le nombre de billets de 100, 20, 10, 5 et 1 dollar(s)
* à retourner après un achat
* \file   Ex_5.cpp
* \author Diab et Abdelrahman
* \date   23 septembre 2018
* Créé le 12 septembre 2018
*/

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string article;
	int prix, argent_a_rendre, entree, resultat, nb_billets;
	const int billet100 = 100, billet20 = 20, billet10 = 10, billet5 = 5, billet1 = 1;

	cout << "Entrer le nom de votre article : ";
	cin >> article;
	cout << "Entrer le prix de votre article : ";
	cin >> prix;
	cout << "Entrer le montant d'argent donnee par le client : ";
	cin >> entree;

	argent_a_rendre = entree - prix;

	nb_billets = argent_a_rendre / billet100;
	cout << "Billet(s) de 100$ : " << nb_billets << endl;
	argent_a_rendre = argent_a_rendre - (nb_billets * billet100);
	
	nb_billets = argent_a_rendre / billet20;
	cout << "Billet(s) de 20$  : " << nb_billets << endl;
	argent_a_rendre = argent_a_rendre - (nb_billets * billet20);
	
	nb_billets = argent_a_rendre / billet10;
	cout << "Billet(s) de 10$  : " << nb_billets << endl;
	argent_a_rendre = argent_a_rendre - (nb_billets * billet10);

	nb_billets = argent_a_rendre / billet5;
	cout << "Billet(s) de 5$   : " << nb_billets << endl;
	argent_a_rendre = argent_a_rendre - (nb_billets * billet5);

	nb_billets = argent_a_rendre / billet1;
	cout << "Billet(s) de 1$   : " << nb_billets << endl;
	argent_a_rendre = argent_a_rendre - (nb_billets * billet1);
}