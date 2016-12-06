#include "stdafx.h"
#include "Perm.h"


Perm::Perm(int N)
{
	this->N = N + 1;
	this->w = new int[this->N];
}

void Perm::init() {
	
	for (int i = 0; i < N; i++) {
		this->w[i] = i;
	}
	random_shuffle(&w[0], &w[this->N-1]);
	w[N-1] = w[0];
}

Perm::~Perm()
{
	delete[] w;
}

int Perm::wierzcho³ek(int N) {
	return w[N];
}

void Perm::wyswietl() {
	cout << endl << endl << "Permutacja : ";
	for (int i = 0; i < N-1; i++) {
		cout << w[i] << " -> ";
	}
	cout << w[N - 1];
}

void Perm::przepisz(Perm *p) {

	for (int i = 0; i < N; i++) {
		this->w[i] = p->wierzcho³ek(i);
	}
}



void Perm::zamienWierzcholki(int a, int b)
{
	int temp = w[a];
	w[a] = w[b];
	w[b] = temp;
	if (a == 0 || b == 0) w[N - 1] = w[0];
}

void Perm::losujSasiada(Perm * perm)
{
	int a, b, temp;

	do{
		a = rand() % (N - 1);
		b = rand() % (N - 1);
	} while (a == b);

	temp = this->w[a];
	this->w[a] = this->w[b];
	this->w[b] = temp;

	if (a == 0 || b == 0) {
		this->w[N - 1] = this->w[0];
	}

}
