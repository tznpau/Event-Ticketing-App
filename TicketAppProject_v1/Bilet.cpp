#include "Bilet.h"

//initializarea variabilei statice
int Bilet::contorBilete = 0;

//constructor implicit
Bilet::Bilet()
{
	auto now = chrono::high_resolution_clock::now();
	auto nanoseconds = chrono::duration_cast<chrono::nanoseconds>(now.time_since_epoch()).count();
	this->UID = nanoseconds;

	this->tip = Standard;

	this->pret = 0;

	this->rand = 0;
	this->loc = 0;

	this->loc = nullptr;

	this->ocupat = false;
}

Bilet::Bilet(long long UID, TipBilet tip, float pret, int rand, int coloana, int** loc, bool ocupat)
{
	auto now = chrono::high_resolution_clock::now();
	auto nanoseconds = chrono::duration_cast<chrono::nanoseconds>(now.time_since_epoch()).count();
	this->UID = nanoseconds;

	if (tip >= 0 && tip <= 1)
	{
		this->tip = tip;
	}

	if (pret >= 1 && pret <= 1000)
	{
		this->pret = pret;
	}

	

}


//metoda de extragere a valorilor din enum (categorie bilet)
TipBilet Bilet::alegeTipBilet(string tip)
{
	if (tip == "Standard")
	{
		return (TipBilet)0;
	}
	else if (tip == "Premium")
	{
		return (TipBilet)1;
	}
	else
		cout << "Tip invalid." << endl;
}