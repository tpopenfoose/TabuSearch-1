#pragma once
#include "TabuElem.h"
class TabuList
{
private:
	int N;
	TabuElem **list;
	int czasTabu;

public:
	TabuList(int N, int czasTabu);
	~TabuList();
	void dodaj(int wierzcholek1, int wierzcholek2);
	void aktualizuj();
	bool sprawdz(int wierzcholek1, int wierzcholek2);
	void restert();

};

