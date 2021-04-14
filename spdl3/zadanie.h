#ifndef ZADANIE_H
#define ZADANIE_H

#include <vector>

using namespace std;

class zadanie
{
public:
	long j, m; //nr zadania i maszyna/operacja
	vector<long> p; //czasy trwania
	zadanie();
};

#endif