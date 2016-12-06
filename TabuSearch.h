#pragma once
#include "Graf.h"
#include "TabuSearch.h"
#include "TabuList.h"
#include "Wynik.h"
#include "Zegar.h"
#include <string>


static class TabuSearch
{
private:
	static void funkcjaAspiracji(Perm * perm, Perm *permTemp, TabuList *tabu, Graf* g, int kosztPerm, int N);
	static void losujWierzcholki(int* a, int* b, int N);
	static int funkcjaDywersyfikacji(Perm* perm, Graf* g, int N);
public:
	static Wynik TabuSearchStart(string plik);
	
};

