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
	int* locuri; //vector locuri
	char* zonaLocuri;
	int nrOcupate;
	Data data;
	Ora ora;
	
public:
	//constructori
	Eveniment();
	Eveniment(const char*, string, int, int, int*, const char*, int, Data, Ora);
	Eveniment(const Eveniment& sursa);

	//destructor
	~Eveniment();

	//metode de acces
	//setteri
	void setTitlu(const char*);
	void setTipEveniment(string);
	void setNrMaxLocuri(int);
	void setNrRanduri(int);
	void setLocuri(int*, int);
	void setZonaLocuri(const char*);
	void setNrOcupate(int);
	void setData(Data);
	void setOra(Ora);

	//getteri
	char* getTitlu();
	string getTipEveniment();
	int getNrMaxLocuri();
	int getNrRanduri();
	int* getLocuri();
	const char* getZonaLocuri();
	int getNrOcupate();
	Data getData();
	Ora getOra();

	//metode
	//metoda de aflare al numarului de locuri disponibile

	//metoda statica
	static int getNrEvenimente();

	//operator=
	Eveniment operator=(const Eveniment& sursa);

	//operatori de citire si de afisare
	friend istream& operator>>(istream& in, Eveniment& sursa);
	friend ostream& operator<<(ostream& out, Eveniment sursa);

	//alti operatori
	int& operator[](int index);
	Eveniment& operator++();
	Eveniment operator++(int);


	//clase friend
	friend class Bilet;
	friend class Data;
	friend class Ora;
};
