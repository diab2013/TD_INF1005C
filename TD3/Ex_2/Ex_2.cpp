// Ex_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int numb = 0;
	int total = 0;
	while (numb < 100 || numb > 500) {
		cout << "Entrer un nombre entre 100 et 500 inclusivement: ";
		cin >> numb;
	}
	string number = to_string(numb);
	for (int i = 0; i < number.length(); i++) {
		total = total + ((number[i]) - '0');
		cout << total;
	}
	if (numb == total) {

	}
}