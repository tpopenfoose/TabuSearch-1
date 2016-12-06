#include "stdafx.h"
#include "TabuSearch.h"

Wynik TabuSearch::TabuSearchStart(string plik)
{
	srand(time(NULL));
	
	LARGE_INTEGER performanceCountEnd, performanceCountStart;
	LARGE_INTEGER  freq; 
	QueryPerformanceFrequency(&freq);

	 

	Graf *g = new Graf();
	
	if (plik=="ft53.atsp" || plik=="ftv33.atsp" || plik== "kro124p.atsp" || plik=="ftv170.atsp") {
		g = new Graf("asym/" + plik, 1);
	}else if (plik=="bays29.tsp") {
		g = new Graf("sym/" + plik, 1);
	}
	else if(plik=="ch130.tsp" || plik =="berlin52.tsp" || plik=="pr299.tsp") {
		g = new Graf("sym/" + plik);
	}


	performanceCountStart = Zegar::startTimer();
	int N = g->rozmiar();
	
	Perm *perm     = new Perm(N);
	Perm *permTemp = new Perm(N);
	Perm *permBest = new Perm(N);
	
	perm     ->init();
	permTemp ->init();
	permBest ->przepisz(perm);
	
	TabuList *tabu = new TabuList(N, N*(N-1)/5);
	
	int maxLiczbaIteracjiBezPoprawy   = 100000;
	int maxLiczbaIteracjiWSasiedztwie = 10000;
	int licznikZdarzeniaKrytycznego   = maxLiczbaIteracjiWSasiedztwie;
	int licznik       = maxLiczbaIteracjiBezPoprawy;
	int kosztPerm     =_MAX_INT_DIG;
	int kosztPermTemp =_MAX_INT_DIG;
	int kosztPermBest = g->oblicz_koszt_permutacji(permBest);

	cout << endl;

	do {
		tabu->aktualizuj();
		kosztPerm     = g->oblicz_koszt_permutacji(perm);
		kosztPermTemp = g->oblicz_koszt_permutacji(permTemp);

		if (kosztPerm > kosztPermTemp)
			perm->przepisz(permTemp);

		if (kosztPerm < kosztPermBest) {
			permBest->przepisz(perm);
			kosztPermBest = g->oblicz_koszt_permutacji(permBest);
			licznik = maxLiczbaIteracjiBezPoprawy;
		}
		else {
			licznikZdarzeniaKrytycznego--;
			if (licznikZdarzeniaKrytycznego == 0) {
				funkcjaDywersyfikacji(perm, g, N);
				permTemp->losujSasiada(perm);
				tabu->restert();
				licznikZdarzeniaKrytycznego = maxLiczbaIteracjiWSasiedztwie;
			}
			else {
				funkcjaAspiracji(perm, permTemp, tabu, g, kosztPerm, N);
			}
		}
		
	licznik--;
	} while (licznik != 0);
	
	performanceCountEnd = Zegar::endTimer();

	cout << "Najlepsze znalezione rozwiazanie posiada koszt : " << kosztPermBest << endl;
	//permBest->wyswietl();

	Wynik wynik;
	wynik.koszt = kosztPermBest;
	wynik.czas = ((performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / (double)freq.QuadPart * 1000);

	return wynik;

	delete perm;
	delete permTemp;
	delete permBest;
	delete tabu;
	delete g;
}

void TabuSearch::funkcjaAspiracji(Perm * perm,Perm* permTemp, TabuList * tabu, Graf *g, int kosztPerm, int N)
{
	Perm *temp = new Perm(N);
	int a, b, kosztAsp;
	float stosunek;
	losujWierzcholki(&a, &b, N);

	while (tabu->sprawdz(a, b)) {

		temp->przepisz(perm);
		temp->zamienWierzcholki(a, b);
		kosztAsp = (g->oblicz_koszt_permutacji(temp));
		stosunek = ((float)kosztAsp) / (float)kosztPerm;
		if ( stosunek < 1.0f) {
			permTemp->przepisz(temp);
			tabu->dodaj(a, b);
			return;
		}
		else {
			losujWierzcholki(&a, &b, N);
		}
	}

	tabu->dodaj(a, b);
	temp->przepisz(perm);
	temp->zamienWierzcholki(a, b);
	permTemp->przepisz(temp);
	delete temp;
	return;
}


void TabuSearch::losujWierzcholki(int * a, int * b, int N)
{
	*a = rand() % (N);
	do {
		*b = rand() % (N);
	} while (*a == *b);
}

int TabuSearch::funkcjaDywersyfikacji(Perm * perm, Graf * g, int N)
{
	Perm *permDyw = new Perm(N);
	perm->init();
	permDyw->init();
	int kosztBest    = g->oblicz_koszt_permutacji(perm);
	int kosztPermDyw = g->oblicz_koszt_permutacji(permDyw);;

	for (int i = 0; i < ceil(N / 2); i++) {
		if (kosztBest > kosztPermDyw) {
			perm->przepisz(permDyw);
			kosztBest = kosztPermDyw;
		}
	}
	return kosztBest;
}
