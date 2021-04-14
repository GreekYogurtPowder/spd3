#include "instancja.h"

using namespace std;

instancja::instancja() {
	long ziarno;

	cout << "Wprowadz ziarno losowania: ";
	cin >> ziarno;
	RandomNumberGenerator generator = RandomNumberGenerator(ziarno);

	cout << "Wprowadz ilosc zadan: ";
	cin >> ilosc_zadan;

	cout << "Wprowadz ilosc operacji/maszyn: ";
	cin >> ilosc_operacji;

	for (int i = 0; i < ilosc_zadan; i++) {
		lista_zadan.push_back(zadanie());
		lista_zadan[i].j = i + 1;

		for (int j = 0; j < ilosc_operacji; j++) {
			lista_zadan[i].p.push_back(generator.nextInt(1, 29));
		}
	}

}

void instancja::wypiszTabele() {
	cout << endl << "j: [";
	for (int i = 0; i < ilosc_zadan; i++) {
		cout << lista_zadan[i].j;
		if (i == ilosc_zadan - 1) { //jesli ostatni element
			cout << "]";
		}
		else {
			cout << ", ";
		}
	}

	cout << endl << "p: [";
	for (int i = 0; i < ilosc_zadan; i++) {
		cout << "[";
		for (int j = 0; j < ilosc_operacji; j++) {
			cout << lista_zadan[i].p[j];
			if (j != ilosc_operacji - 1) {
				cout << ", ";
			}
		}
		cout << "]";

		if (i == ilosc_zadan - 1) {
			cout << "]";
		}
		else {
			cout << ", ";
		}
	}
}
 
vector<long> instancja::domyslnePi() {
	vector<long> pi;
	for (int i = 0; i < ilosc_zadan; i++) {
		pi.push_back(lista_zadan[i].j);
	}
	return pi;
}

void instancja::wypiszPi(vector<long> pi) {
	cout << endl << "Pi: [";
	for (int i = 0; i < pi.size(); i++) {
		cout << pi[i];
		if (i == pi.size() - 1) {
			cout << "]";
		}
		else {
			cout << ", ";
		}
	}
}

long instancja::funkcja_oceny(vector<long> pi) {
	vector<zadanie> posortowana_lista;
	vector<vector<long>> czas_C; //moment zakonczenia

	for (int i = 0; i < ilosc_zadan; i++) {
		posortowana_lista.push_back(lista_zadan[pi[i] - 1]);
		czas_C.push_back(vector<long>());
	}

	for (int j = 0; j < ilosc_operacji; j++) {
		for (int i = 0; i < ilosc_zadan; i++) {

			if (j == 0) {
				if (i == 0) {
					czas_C[i].push_back(posortowana_lista[i].p[j]);
				}
				else {
					czas_C[i].push_back(czas_C[i - 1][j] + posortowana_lista[i].p[j]);
				}
			}
			else {
				if (i == 0) {
					czas_C[i].push_back(czas_C[i][j - 1] + posortowana_lista[i].p[j]);
				}
				else {
					if (czas_C[i - 1][j] < czas_C[i][j - 1]) {
						czas_C[i].push_back(czas_C[i][j - 1] + posortowana_lista[i].p[j]);
					}
					else {
						czas_C[i].push_back(czas_C[i - 1][j] + posortowana_lista[i].p[j]);
					}
				}
			}
		}
	}

	long Cmax = 0;

	for (int i = 0; i < ilosc_operacji; i++) {
		if (czas_C[ilosc_zadan - 1][i] > Cmax) {
			Cmax = czas_C[ilosc_zadan - 1][i];
		}
	}

	return Cmax;
}

void instancja::wypiszWyniki(vector<long> pi) {
	
	vector<zadanie> posortowana_lista;
	vector<vector<long>> czas_C; //moment zakonczenia
	vector<vector<long>> czas_S; //moment rozpoczecia

	for (int i = 0; i < ilosc_zadan; i++) {
		posortowana_lista.push_back(lista_zadan[pi[i] - 1]);
		czas_C.push_back(vector<long>());
		czas_S.push_back(vector<long>());
	}

	for (int j = 0; j < ilosc_operacji; j++) {
		for (int i = 0; i < ilosc_zadan; i++) {
			
			if (j == 0) {
				if (i == 0) {
					czas_C[i].push_back(posortowana_lista[i].p[j]);
				}
				else {
					czas_C[i].push_back(czas_C[i - 1][j] + posortowana_lista[i].p[j]);
				}
			}
			else {
				if (i == 0) {
					czas_C[i].push_back(czas_C[i][j - 1] + posortowana_lista[i].p[j]);
				}
				else {
					if (czas_C[i - 1][j] < czas_C[i][j - 1]) {
						czas_C[i].push_back(czas_C[i][j - 1] + posortowana_lista[i].p[j]);
					}
					else {
						czas_C[i].push_back(czas_C[i - 1][j] + posortowana_lista[i].p[j]);
					}
				}
			}
		}
	}

	for (int i = 0; i < ilosc_zadan; i++) {
		for (int j = 0; j < ilosc_operacji; j++) {
			czas_S[i].push_back(czas_C[i][j] - posortowana_lista[i].p[j]);
		}
	}

	cout << "S: [";
	for (int i = 0; i < ilosc_zadan; i++) {
		cout << "[";
		for (int j = 0; j < ilosc_operacji; j++) {
			cout << czas_S[i][j];
			if (j != ilosc_operacji - 1) {
				cout << ", ";
			}
		}
		cout << "]";

		if (i == ilosc_zadan - 1) {
			cout << "]";
		}
		else {
			cout << ", ";
		}
	}

	cout << endl << "C: [";
	for (int i = 0; i < ilosc_zadan; i++) {
		cout << "[";
		for (int j = 0; j < ilosc_operacji; j++) {
			cout << czas_C[i][j];
			if (j != ilosc_operacji - 1) {
				cout << ", ";
			}
		}
		cout << "]";

		if (i == ilosc_zadan - 1) {
			cout << "]";
		}
		else {
			cout << ", ";
		}
	}

	cout << endl << "Cmax: " << funkcja_oceny(pi) <<endl;
}

vector<long> instancja::johnson() {
	
	vector<long> pi; // wektor z wynikowa kolejnoscia pi
	vector<zadanie> wektor_N; //wektor zadan nieuszeregowanych
	long l = 0;
	long k = ilosc_zadan - 1;

	for (int i = 0; i < ilosc_zadan; i++) { //wypelnienie wektora zadan nieuszeregowanych
		wektor_N.push_back(lista_zadan[i]);
		pi.push_back(0);
	}

	long wartosc_minimalna;
	long indeks_j_minimalnego_zadania;

	while (!wektor_N.empty()) {
		
		wartosc_minimalna = wektor_N[0].p[0];
		indeks_j_minimalnego_zadania = 0;

		for (int j = 0; j < wektor_N.size(); j++) { //znalezienie najmniejszej operacji z nieprzydzielonych zadan
			if(wektor_N[j].p[0] < wartosc_minimalna) {
				wartosc_minimalna = wektor_N[j].p[0];
				indeks_j_minimalnego_zadania = j;
			}

			if (wektor_N[j].p[ilosc_operacji-1] < wartosc_minimalna) {
				wartosc_minimalna = wektor_N[j].p[ilosc_operacji - 1];
				indeks_j_minimalnego_zadania = j;
			}
		}

		if (wektor_N[indeks_j_minimalnego_zadania].p[0] < wektor_N[indeks_j_minimalnego_zadania].p[ilosc_operacji - 1]) {
			pi[l] = wektor_N[indeks_j_minimalnego_zadania].j;
			l++;
		}
		else {
			pi[k] = wektor_N[indeks_j_minimalnego_zadania].j;
			k--;
		}

		wektor_N.erase(wektor_N.begin() + indeks_j_minimalnego_zadania);

	}

	return pi;
}