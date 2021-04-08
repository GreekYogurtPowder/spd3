#include <iostream>
#include "instancja.h"
#include "RandomNumberGenerator.h"
using namespace std;


int main()
{
	instancja inst = instancja();

	cout << endl << "-----ZADANIA-----" << endl;
	inst.wypiszTabele();
	inst.wypiszPi();

	/*
	cout << endl << endl << "-----PRZED SCHREGE-----" << endl;
	inst.calculate();

	cout << endl << endl << "-----PO SCHREGE-----" << endl;
	vector<long> pi = inst.Schrage();
	inst.wypiszPi(pi);
	inst.calculate(pi);
	*/

	cout << endl << endl;
	return 0;
}