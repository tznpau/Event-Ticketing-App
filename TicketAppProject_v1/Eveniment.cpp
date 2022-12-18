#include "Eveniment.h"

//initializarea variabilei statice
int Eveniment::contorEvenimente = 0;

//constructor implicit
Eveniment::Eveniment() : idEveniment(Eveniment::contorEvenimente++)
{
	this->titlu = new char[strlen("N/A") + 1];
	strcpy_s(this->titlu, strlen("N/A") + 1, "N/A");

	this->tipEveniment = "N/A";

	this->nrMaxLocuri = 0;
	this->nrRanduri = 0;
	this->nrLocuriPeRand = 0;

	Data* data = new Data(0, 0, 2023);
	Ora* ora = new Ora(00, 00);

}

//constructor cu toti parametri
Eveniment::Eveniment(const char* titlu, string tipEveniment, int nrMaxLocuri, int nrRanduri, int nrLocuriPeRand, Data data, Ora ora) : idEveniment(Eveniment::contorEvenimente++)
{
	if (strlen(titlu) > 2)
	{
		this->titlu = new char[strlen(titlu) + 1];
		strcpy_s(this->titlu, strlen(titlu) + 1, titlu);
	}
	else
	{
		throw "Titlul evenimentului nu este valid.";
		this->titlu = new char[strlen("N/A") + 1];
		strcpy_s(this->titlu, strlen("N/A") + 1, "N/A");
	}

	if (tipEveniment.length() >= 4)
	{
		this->tipEveniment = tipEveniment;
	}
	else
		throw "Tipul evenimentului nu este valid.";

	if (nrMaxLocuri >= 10 && nrMaxLocuri <= 500)
	{
		this->nrMaxLocuri = nrMaxLocuri;
	}
	else
		throw "Numarul maxim de locuri nu este valid.";
		

	if (nrRanduri >= 2 && nrRanduri <= 50)
	{
		this->nrRanduri = nrRanduri;
	}
	else
		throw "Numarul de randuri nu este valid.";

	if (nrLocuriPeRand >= 5 && nrLocuriPeRand <= 10)
	{
		this->nrLocuriPeRand = nrLocuriPeRand;
	}
	else
		throw "Numarul de locuri pe rand nu este valid.";

	if (data.dataValida(data.zi, data.luna, data.an))
	{
		this->data = data;
	}
	else
		throw "Data nu este valida.";

	if (ora.oraValida(ora.ora, ora.minut))
	{
		this->ora = ora;
	}
	else
		throw "Ora nu este valida.";

}

//constructor de copiere
Eveniment::Eveniment(const Eveniment& sursa) : idEveniment(Eveniment::contorEvenimente++)
{
	this->titlu = new char[strlen(sursa.titlu) + 1];
	strcpy_s(this->titlu, strlen(sursa.titlu) + 1, sursa.titlu);

	this->tipEveniment = sursa.tipEveniment;

	this->nrMaxLocuri = sursa.nrMaxLocuri;
	this->nrRanduri = sursa.nrRanduri;
	this->nrLocuriPeRand = sursa.nrLocuriPeRand;

	this->data = sursa.data;
	this->ora = sursa.ora;
}

//destructor
Eveniment::~Eveniment()
{
	if (this->titlu != nullptr)
	{
		delete[] this->titlu;
		this->titlu = nullptr;
	}
}

//operator=
Eveniment Eveniment::operator=(const Eveniment& sursa)
{
	delete[] this->titlu;

	this->titlu = new char[strlen(sursa.titlu) + 1];
	strcpy_s(this->titlu, strlen(sursa.titlu) + 1, sursa.titlu);

	this->tipEveniment = sursa.tipEveniment;

	this->nrMaxLocuri = sursa.nrMaxLocuri;
	this->nrRanduri = sursa.nrRanduri;
	this->nrLocuriPeRand = sursa.nrLocuriPeRand;

	this->data = sursa.data;
	this->ora = sursa.ora;

	return *this;
}

//metode de acces
//setteri
void Eveniment::setTitlu(const char* titlu)
{
	delete[] this->titlu;
	if (strlen(titlu) > 2)
	{
		this->titlu = new char[strlen(titlu) + 1];
		strcpy_s(this->titlu, strlen(titlu) + 1, titlu);
	}
	else
		throw "Titlul este invalid.";
}

void Eveniment::setTipEveniment(string tipEveniment)
{
	if (tipEveniment.length() >= 4)
	{
		this->tipEveniment = tipEveniment;
	}
	else
		throw "Tipul evenimentului nu este valid.";
}

void Eveniment::setNrMaxLocuri(int nrMaxLocuri)
{
	if (nrMaxLocuri >= 10 && nrMaxLocuri <= 500)
	{
		this->nrMaxLocuri = nrMaxLocuri;
	}
	else
		throw "Numarul maxim de locuri nu este valid.";
}

void Eveniment::setNrRanduri(int nrRanduri)
{
	if (nrRanduri >= 2 && nrRanduri <= 50)
	{
		this->nrRanduri = nrRanduri;
	}
	else
		throw "Numarul de randuri nu este valid.";
}

void Eveniment::setNrLocuriPeRand(int nrLocuriPeRand)
{
	if (nrLocuriPeRand >= 5 && nrLocuriPeRand <= 10)
	{
		this->nrLocuriPeRand = nrLocuriPeRand;
	}
	else
		throw "Numarul de locuri pe rand nu este valid.";
}

void Eveniment::setData(Data data)
{
	if (data.dataValida(data.zi, data.luna, data.an))
	{
		this->data = data;
	}
	else
		throw "Data nu este valida.";
}

void Eveniment::setOra(Ora ora)
{
	if (ora.oraValida(ora.ora, ora.minut))
	{
		this->ora = ora;
	}
	else
		throw "Ora nu este valida.";
}

//getteri
char* Eveniment::getTitlu()
{
	return this->titlu;
}

string Eveniment::getTipEveniment()
{
	return this->tipEveniment;
}

int Eveniment::getNrMaxLocuri()
{
	return this->nrMaxLocuri;
}

int Eveniment::getNrRanduri()
{
	return this->nrRanduri;
}

int Eveniment::getNrLocuriPeRand()
{
	return this->nrLocuriPeRand;
}

Data Eveniment::getData()
{
	return this->data;
}

Ora Eveniment::getOra()
{
	return this->ora;
}

//operatori de citire si de afisare
istream& operator>>(istream& in, Eveniment& sursa)
{
	//titlu
	cout << "Introduceti titlul evenimentului: " << endl;
	char buffer[300];
	in.getline(buffer, 300);
	delete[] sursa.titlu;
	sursa.titlu = new char[strlen(buffer) + 1];
	strcpy_s(sursa.titlu, strlen(buffer) + 1, buffer);

	//tipEveniment
	cout << "Introduceti tipul evenimentului: " << endl;
	char bufft[100];
	in.getline(bufft, 100);
	sursa.tipEveniment = bufft;

	//nrMaxLocuri
	cout << "Introduceti numarul maxim de locuri disponibile la eveniment: " << endl;
	in >> sursa.nrMaxLocuri;

	//nrRanduri
	cout << "Introduceti numarul de randuri disponibile la eveniment: " << endl;
	in >> sursa.nrRanduri;
	
	//nrLocuriPeRand
	cout << "Introduceti numarul de locuri disponibile pe fiecare rand: " << endl;
	in >> sursa.nrLocuriPeRand;

	return in;
}

ostream& operator<<(ostream& out, Eveniment sursa)
{
	out << "Titlu: " << sursa.titlu << endl;
	out << "Eveniment: " << sursa.tipEveniment << endl;
	out << "Numar maxim de locuri disponibile: " << sursa.nrMaxLocuri << endl;
	out << "Numar de randuri disponibile: " << sursa.nrRanduri << endl;
	out << "Numar de locuri disponibile pe fiecare rand: " << sursa.nrLocuriPeRand << endl;

	return out;
}