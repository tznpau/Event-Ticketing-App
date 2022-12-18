#include "Bilet.h"

//initializarea variabilei statice
int Bilet::contorBilete = 0;

//constructor implicit
Bilet::Bilet() : nrBilet(Bilet::contorBilete++)
{
	auto now = chrono::high_resolution_clock::now();
	auto nanoseconds = chrono::duration_cast<chrono::nanoseconds>(now.time_since_epoch()).count();
	this->UID = nanoseconds;

	this->tip = Standard;

	this->pret = 0;

	this->rand = 0;
	this->loc = 0;

	this->ocupat = false;
}

//constructor cu toti parametri
Bilet::Bilet(long long UID, TipBilet tip, float pret, int rand, int loc, bool ocupat) : nrBilet(Bilet::contorBilete++)
{
	auto now = chrono::high_resolution_clock::now();
	auto nanoseconds = chrono::duration_cast<chrono::nanoseconds>(now.time_since_epoch()).count();
	this->UID = nanoseconds;

	if (tip >= 0 && tip <= 1)
	{
		this->tip = tip;
	}
	else
		throw "Tip invalid.";

	if (pret >= 1 && pret <= 1000)
	{
		this->pret = pret;
	}
	else
		throw "Pretul nu se incadreaza in limite. [1, 1000 lei]";

	this->rand = rand;
	this->loc = loc;
	
	this->ocupat = ocupat;
}

//constructor de copiere
Bilet::Bilet(const Bilet& sursa) : nrBilet(Bilet::contorBilete++)
{
	this->UID = sursa.UID;
	this->tip = sursa.tip;
	this->pret = sursa.pret;
	this->rand = sursa.rand;
	this->loc = sursa.loc;
	this->ocupat = sursa.ocupat;
}

//operator=
Bilet& Bilet::operator=(const Bilet& sursa)
{
	this->UID = sursa.UID;
	this->tip = sursa.tip;
	this->pret = sursa.pret;
	this->rand = sursa.rand;
	this->loc = sursa.loc;
	this->ocupat = sursa.ocupat;

	return *this;
}

//metode de acces
//setteri
void Bilet::setUID(long long)
{
	auto now = chrono::high_resolution_clock::now();
	auto nanoseconds = chrono::duration_cast<chrono::nanoseconds>(now.time_since_epoch()).count();
	this->UID = nanoseconds;
}

void Bilet::setTipBilet(TipBilet tip)
{
	if (tip >= 0 && tip <= 1)
	{
		this->tip = tip;
	}
	else
		throw "Tip invalid.";
}

void Bilet::setPret(float pret)
{
	if (pret >= 1 && pret <= 1000)
	{
		this->pret = pret;
	}
	else
		throw "Pretul nu se incadreaza in limite. [1, 1000 lei]";
}

void Bilet::setRand(int rand)
{
	this->rand = rand;
}

void Bilet::setLoc(int loc)
{
	this->loc = loc;
}

void Bilet::setOcupat(bool ocupat)
{
	this->ocupat = ocupat;
}

//getteri
long long Bilet::getUID()
{
	return this->UID;
}

TipBilet Bilet::getTipBilet()
{
	return this->tip;
}

float Bilet::getPret()
{
	return this->pret;
}

int Bilet::getRand()
{
	return this->rand;
}

int Bilet::getLoc()
{
	return this->loc;
}

bool Bilet::getOcupat()
{
	return this->ocupat;
}

//operatori de citire si de afisare
istream& operator>>(istream& in, Bilet& sursa)
{
	//tip
	int auxTip;
	cout << "Selecteaza tipul biletului (Standard - 0, Premium - 1): " << endl;
	in >> auxTip;
	if ((auxTip >= 0) && (auxTip <= 3))
	{
		sursa.tip = (TipBilet)auxTip;
	}

	//pret
	cout << "Introduce pretul biletului: " << endl;
	in >> sursa.pret;

	//rand
	cout << "Introduce randul: " << endl;
	in >> sursa.rand;

	//loc
	cout << "Introduce locul: " << endl;
	in >> sursa.loc;

	//ocupat
	cout << "Introduce disponibilitatea locului (Ocupat - 1, Disponibil - 0): ";
	in >> sursa.ocupat;

	return in;
}

ostream& operator<<(ostream& out, Bilet sursa)
{
	out << "Numar bilet: " << sursa.nrBilet << endl;
	out << "ID unic: " << sursa.UID << endl;
	out << "Tip bilet: " << sursa.tip << endl;
	out << "Pret: " << sursa.pret << endl;
	out << "Rand: " << sursa.rand << endl;
	out << "Loc: " << sursa.loc << endl;
	out << "Disponibilitate: ";
	if (sursa.ocupat == true)
	{
		out << "Ocupat" << endl;
	}
	else
		out << "Disponibil" << endl;

	return out;
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
	{
		cout << "Tip invalid." << endl;
		return (TipBilet)0;
	}
}