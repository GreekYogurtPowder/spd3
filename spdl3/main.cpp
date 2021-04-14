#include <time.h>
#include "instancja.h"
using namespace std;

int main()
{
	instancja inst = instancja();
	time_t  start, stop;

	cout << endl << "-----ZADANIA-----" << endl;
	inst.wypiszTabele();

	cout << endl<< endl << "-----PERMUTACJA NATURALNA-----" << endl;
	inst.wypiszPi(inst.domyslnePi());
	cout << endl;
	inst.wypiszWyniki(inst.domyslnePi());

	cout << endl << "-----JOHNSON-----" << endl;
	time(&start);
	vector<long> pi = inst.johnson();
	time(&stop);
	time_t czas = stop - start;
	inst.wypiszPi(pi);
	cout << endl;
	inst.wypiszWyniki(pi);
	cout << "Czas dzialania: " << czas << " s";

	cout << endl << endl;
	return 0;
}