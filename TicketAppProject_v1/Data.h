#pragma once
#include <iostream>

using namespace std;

class Data
{
private:
	int zi;
	int luna;
	int an;

public:
	//constructori
	Data();
	Data(int, int, int);
	Data(const Data& sursa);

	//metode de acces
	//setteri
	void setZi(int);
	void setLuna(int);
	void setAn(int);
	//getteri
	int getZi();
	int getLuna();
	int getAn();

	//metode
	bool dataValida(int, int, int);

	//operator=
	Data operator=(const Data& sursa);

	//operatori de citire si afisare
	friend ostream& operator<<(ostream& out, Data sursa);
	friend istream& operator>>(istream& in, Data& sursa);

	//alti operatori
	bool operator==(Data sursa);
	bool operator!=(Data sursa);
	bool operator<(Data sursa);
	bool operator>(Data sursa);

	//clase friend
	friend class Eveniment;
};