#include "stdafx.h"
#include "TabuList.h"


TabuList::TabuList(int N, int czasTabu)
{
	this->czasTabu = czasTabu;
	this->N = N;
	list = new TabuElem*[N];
	for (int i = 0; i < this->N; i++)
	{
		list[i] = new TabuElem[N];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			list[i][j].tabu = 0;
			list[i][j].czas = 0;
		}
	}
}


TabuList::~TabuList()
{
	for (int i = 0; i < N; i++)
	{
		delete[] list[i];
	}
	delete[] list;
}

void TabuList::dodaj(int wierzcholek1, int wierzcholek2)
{
	list[wierzcholek1][wierzcholek2].tabu = 1;
	list[wierzcholek1][wierzcholek2].czas = czasTabu;
}

void TabuList::aktualizuj()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (list[i][j].tabu == 1)
				if (list[i][j].czas != 0)
					list[i][j].czas--;
				else {
					list[i][j].tabu = 0;
					list[j][i].tabu = 0;
				}
		}
	}
}

bool TabuList::sprawdz(int wierzcholek1, int wierzcholek2)
{
	return list[wierzcholek1][wierzcholek2].tabu==true ? true : false;
}

void TabuList::restert()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			list[i][j].tabu = 0;
			list[i][j].czas = 0;
		}
	}
}