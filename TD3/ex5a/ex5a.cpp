// ex5a.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cmath>
#include <cctype>
#include <iomanip>
#include <vector>
#include <array>


using namespace std;



int main()
{
	//saisie du nombre de points et initialisation des variables urtilisés pour le traiteemnt
	cout << "saisir un entier entre 1 et 10 designant le nombre de points : " << endl;
	int NBR_PTS;
	cin >> NBR_PTS ;
	
	double moyenneX=0, moyenneY=0, dproche=0, dloin = 0, dcalculee = 0, ptsprocheX = 0, ptsloinX = 0, ptsprocheY= 0, ptsloinY=0;

	//remplissage du tableau


	double tableau[10][2];
	for ( int ligne = 0; ligne < NBR_PTS; ligne++)
	{   for (int colone = 0; colone < 2 ; colone++)
		{
			cout << "Veuillez entrer les coordonnees x puis y du point" << ligne +1 << " . " << endl;
			cin >> tableau [ligne] [colone];
		}
	}

	///////analyse et affichage des données

	for (int ligne = 0; ligne < NBR_PTS; ligne++) 
	{
		moyenneX += tableau[ligne][0];         
		moyenneY += tableau[ligne][1];
	}
	
	moyenneX = moyenneX / NBR_PTS;
	moyenneY = moyenneY / NBR_PTS;
	
	cout << "\n" << endl;
	cout << "les coordonnes du centre de gravite sont : " << moyenneX << " ; " << moyenneY << " . "<< endl;

	for (int ligne = 0; ligne < NBR_PTS; ligne++)
	{
		dcalculee = sqrt(pow(moyenneX - tableau[ligne][0], 2) + pow(moyenneY - tableau[ligne][1], 2));
		if (ligne == 0)
		{
			dproche = dcalculee;
			ptsprocheX = tableau[ligne][0];
			ptsprocheY = tableau[ligne][1];
			dloin = dcalculee;
			ptsloinX = tableau[ligne][0];
			ptsloinY = tableau[ligne][1];
		}



		if (dcalculee < dproche)
		{
			dproche = dcalculee;
			ptsprocheX = tableau[ligne][0];
			ptsprocheY = tableau[ligne][1];
		}

		if (dcalculee > dloin)
		{
			dloin = dcalculee;
			ptsloinX = tableau[ligne][0];
			ptsloinY = tableau[ligne][1];
		}


	}
	cout << "Les coordonnees du point le plus proche du centre de gravite sont : " << ptsprocheX << " , " << ptsprocheY << " . " << endl;
	cout << "Les coordonnees du point le plus loin du centre de gravite sont : " << ptsloinX << " , " << ptsloinY << " . " << endl;
}

	




