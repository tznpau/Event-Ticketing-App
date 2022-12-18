#pragma once
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Data.h"
#include "Ora.h"

using namespace std;

class Eveniment
{
private:
	const int idEveniment = 0;
	static int contorEvenimente;
	char* titlu;
	string tipEveniment;
	int nrMaxLocuri;
	int nrRanduri;
	int nrLocuriPeRand;
	Data data;
	Ora ora;
	
public:
	//constructori
	Eveniment();
	Eveniment(const char*, string, int, int, int, Data, Ora);
	Eveniment(const Eveniment& sursa);
	Eveniment(int, int);

	//destructor
	~Eveniment();

	//metode de acces
	//setteri
	void setTitlu(const char*);
	void setTipEveniment(string);
	void setNrMaxLocuri(int);
	void setNrRanduri(int);
	void setNrLocuriPeRand(int);
	void setData(Data);
	void setOra(Ora);

	//getteri
	char* getTitlu();
	string getTipEveniment();
	int getNrMaxLocuri();
	int getNrRanduri();
	int getNrLocuriPeRand();
	Data getData();
	Ora getOra();

	//metode
	//int** locuriLibere(Bilet*** matrice, int nrLocuriPeRand, int nrRanduri);

	//operator=
	Eveniment operator=(const Eveniment& sursa);

	//operatori de citire si de afisare
	friend istream& operator>>(istream& in, Eveniment& sursa);
	friend ostream& operator<<(ostream& out, Eveniment sursa);

	//clase friend
	friend class Bilet;
	friend class Data;
	friend class Ora;
};
