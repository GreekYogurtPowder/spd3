#ifndef INSTANCJA_H
#define INSTANCJA_H

#include "zadanie.h"
#include "RandomNumberGenerator.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class instancja
{
public:
	vector<zadanie> lista_zadan;
	long ilosc_zadan;
	long ilosc_operacji;

	instancja();
	void wypiszTabele();
	
	void wypiszPi();
	void wypiszPi(vector<long> pi);

	void funkcja_oceny();

	/*
	void calculate();
	void calculate(vector<long> pi);
	vector<long> Schrage();
	*/
};

#endif