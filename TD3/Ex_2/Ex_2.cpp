// Ex_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int numb = 100;
	int total = 0;
	cout << "Les nombres satisfaisant la regle sont les suivants : " << "\n" << endl;
	
	while (numb <= 500) {
		
		double chiffre1 = numb/ 100, chiffre2 = (numb%100)/10, chiffre3 = numb%10;
		total = pow(chiffre1, 3.0) + pow(chiffre2, 3.0) + pow(chiffre3, 3.0);
		
		if (total == numb) {
			cout << numb << endl;
		}
		numb++;
	}
}