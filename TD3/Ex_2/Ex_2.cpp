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
	while (numb <= 500) {
		string numero = to_string(numb);
		double chiffre1 = numero[0]-48, chiffre2 = numero[1]-48, chiffre3 = numero[2]-48;
		total = pow(chiffre1, 3.0) + pow(chiffre2, 3.0) + pow(chiffre3, 3.0);
		if (total == numb) {
			cout << numb << endl;
		}
		numb++;
	}
}