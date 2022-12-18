#pragma once
#include <iostream>

using namespace std;

class Ora
{
private:
	int ora;
	int minut;

public:
	//constructori
	Ora();
	Ora(int, int);
	Ora(const Ora& sursa);

	//metode de acces
	//setteri
	void setOra(int);
	void setMinut(int);
	//getteri
	int getOra();
	int getMinut();

	//metode
	bool oraValida(int, int);

	//operator=
	Ora& operator=(const Ora& sursa);

	//operatori de citire si afisare
	friend ostream& operator<<(ostream& out, Ora sursa);
	friend istream& operator>>(istream& in, Ora& sursa);

	//alti operatori
	Ora operator+(const Ora& sursa);
	Ora operator+(int);
	Ora operator-=(const Ora& sursa);

	//clase friend
	friend class Eveniment;
};