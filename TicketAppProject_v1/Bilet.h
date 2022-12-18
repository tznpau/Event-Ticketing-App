#pragma once
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <chrono>
#include "User.h"
#include "Eveniment.h"

using namespace std;

enum TipBilet {Standard, Premium};

//explicatie enum:
//bilet Standard = standard, optiunea cu pretul cel mai ieftin
//bilet Premium = optiunea mai scumpa, corespondenta zonei cu mai putine locuri disponibile

class Bilet
{
private:
	const int nrBilet = 0;
	static int contorBilete;
	long long UID; //ID unic ce nu poate fi ghicit
	TipBilet tip;
	float pret;
	int rand;
	int coloana;
	int** loc;
	bool ocupat;
	
public:
	//constructori
	Bilet();
	Bilet(long long, TipBilet, float, int, int, int**, bool);
	Bilet(const Bilet& sursa);

	//metode de acces
	//setteri
	void setUID(long long);
	void setTipBilet(TipBilet);
	void setPret(float);
	void setRand(int);
	void setColoana(int);
	void setLoc(int**);

	//getteri
	long long getUID();
	TipBilet getTipBilet();
	float getPret();
	int getRand();
	int getColoana();
	int** getLoc();

	//metode
	TipBilet alegeTipBilet(string tip);
	//metoda de aflare a disponibilitatii locului

	//operator=
	Bilet& operator=(const Bilet& sursa);

	//operatori de citire si de afisare
	friend istream& operator>>(istream& in, Bilet& sursa);
	friend ostream& operator<<(ostream& out, Bilet sursa);
	

	//friend classes
	//friend class User;
	friend class Eveniment;
};



