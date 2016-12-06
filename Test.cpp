#include "stdafx.h"
#include "Test.h"



void Test::TestStart()
{
	Wynik wynik;
	fstream plik;
	plik.open("Wyniki.txt",ios::out);

	if (plik.is_open()) {

		long int Koszt=0;
		double Czas=0;

		
		plik << endl << endl << "TSP ___________________" << endl;
		for (int i = 0; i < N; i++) {
			wynik = TabuSearch::TabuSearchStart("bays29.tsp");
			Koszt += wynik.koszt;
			Czas += wynik.czas;
		}
		Koszt /= N;
		Czas /= N;
		plik << "bays29.tsp : " << Koszt << " , czas : " << Czas << endl;
		Koszt = 0;
		Czas = 0;

		for (int i = 0; i < N; i++) {
			wynik = TabuSearch::TabuSearchStart("berlin52.tsp");
			Koszt += wynik.koszt;
			Czas += wynik.czas;
		}
		Koszt /= N;
		Czas /= N;
		plik << "berlin52.tsp : " << Koszt << " , czas : " << Czas << endl;
		Koszt = 0;
		Czas = 0;


		for (int i = 0; i < N; i++) {
			wynik = TabuSearch::TabuSearchStart("ch130.tsp");
			Koszt += wynik.koszt;
			Czas += wynik.czas;
		}
		Koszt /= N;
		Czas /= N;
		plik << "ch130.tsp : " << Koszt << " , czas : " << Czas << endl;
		Koszt = 0;
		Czas = 0;


		for (int i = 0; i < N; i++) {
		wynik = TabuSearch::TabuSearchStart("pr299.tsp");
		Koszt += wynik.koszt;
		Czas += wynik.czas;
		}
		Koszt /= N;
		Czas /= N;
		plik << "pr299.tsp : " << Koszt << " , czas : " << Czas << endl;
		Koszt = 0;
		Czas = 0;


	
		plik << endl << endl << "ATSP ___________________" << endl;

		for (int i = 0; i < N; i++) {
			wynik = TabuSearch::TabuSearchStart("ftv33.atsp");
			Koszt += wynik.koszt;
			Czas += wynik.czas;
		}
		Koszt /= N;
		Czas /= N;
		plik << "ftv33.atsp : " << Koszt << " , czas : " << Czas << endl;
		Koszt = 0;
		Czas = 0;


		for (int i = 0; i < N; i++) {
			wynik = TabuSearch::TabuSearchStart("ft53.atsp");
			Koszt += wynik.koszt;
			Czas += wynik.czas;
		}
		Koszt /= N;
		Czas /= N;
		plik << "ft53.atsp : " << Koszt << " , czas : " << Czas << endl;
		Koszt = 0;
		Czas = 0;
	
	
		for (int i = 0; i < N; i++) {
			wynik = TabuSearch::TabuSearchStart("kro124p.atsp");
			Koszt += wynik.koszt;
			Czas += wynik.czas;
		}
		Koszt /= N;
		Czas /= N;
		plik << "kro124p.atsp : " << Koszt << " , czas : " << Czas << endl;
		Koszt = 0;
		Czas = 0;
		
		

		for (int i = 0; i < N; i++) {
		wynik = TabuSearch::TabuSearchStart("ftv170.atsp");
		Koszt += wynik.koszt;
		Czas += wynik.czas;
		}
		Koszt /= N;
		Czas /= N;
		plik << "ftv170.atsp : " << Koszt << " , czas : " << Czas << endl;
		Koszt = 0;
		Czas = 0;

	plik.close();
	
	}else {
		system("CLS");
		cout << "Nie mo¿na utworzyc pliku wynikowego."<<endl;
	}
}
