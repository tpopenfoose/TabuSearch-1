#pragma once
#include <algorithm>
#include "TabuList.h"
class Perm
{
private:
	int *w;
	int N;

public:
	Perm(int N);
	~Perm();
	void init();
	int wierzcho³ek(int N);
	void wyswietl();
	void przepisz(Perm *p);
	void zamienWierzcholki(int a, int b);
	void losujSasiada(Perm *perm);
	
};
