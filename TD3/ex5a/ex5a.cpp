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
	//saisie du nombre de points
	cout << "saisir un entier entre 1 et 10 designant le nombre de points : " << endl;
	int nmbr_pt;
	cin >>  nmbr_pt;

	const int nmbr_pts = nmbr_pt; 
	//remplissage du tableau

	double tableau[10][10];
	
	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= 10; i++) 
		{
			cout << "entrer les coordonnees en y du points " << i << " : " << endl;
		    cin >> tableau[j]


		}






	}




	
	









}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
