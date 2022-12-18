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

	this->locuri = nullptr;

	this->zonaLocuri = new char[strlen("N/A") + 1];
	strcpy_s(this->zonaLocuri, strlen("N/A") + 1, "N/A");

	this->nrOcupate = 0;

	Data* data = new Data(0, 0, 2023);
	Ora* ora = new Ora(00, 00);

}

//constructor cu toti parametri
Eveniment::Eveniment(const char* titlu, string tipEveniment, int nrMaxLocuri, int nrRanduri, int* locuri, const char* zonaLocuri, int nrOcupate, Data data, Ora ora) : idEveniment(Eveniment::contorEvenimente++)
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
		

	if (nrRanduri > 0)
	{
		this->nrRanduri = nrRanduri;
	}
	else
		throw "Numarul de randuri nu este valid.";

	if (nrMaxLocuri > 0 && locuri != nullptr)
	{
		this->nrMaxLocuri = nrMaxLocuri;
		this->locuri = new int[nrMaxLocuri];
		for (int i = 0; i < nrMaxLocuri; i++)
		{
			if (locuri[i] >= 0)
			{
				this->locuri[i] = locuri[i];
			}
			else
			{
				this->locuri[i] = 0;
			}
		}
	}
	else
	{
		this->nrMaxLocuri = 0;
		this->locuri = nullptr;
	}

	if (strlen(zonaLocuri) > 3)
	{
		this->zonaLocuri = new char[strlen(zonaLocuri) + 1];
		strcpy_s(this->zonaLocuri, strlen(zonaLocuri) + 1, zonaLocuri);
	}
	else
	{
		throw "Zona nu este valida.";
		this->zonaLocuri = new char[strlen("N/A") + 1];
		strcpy_s(this->zonaLocuri, strlen("N/A") + 1, "N/A");
	}

	this->nrOcupate;

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

	this->nrRanduri = sursa.nrRanduri;

	this->nrMaxLocuri = sursa.nrMaxLocuri;
	this->locuri = new int[sursa.nrMaxLocuri];
	for (int i = 0; i < sursa.nrMaxLocuri; i++)
	{
		if (sursa.locuri[i] >= 0)
		{
			this->locuri[i] = sursa.locuri[i];
		}
		else
		{
			this->locuri[i] = 0;
		}
	}

	this->zonaLocuri = new char[strlen(sursa.zonaLocuri) + 1];
	strcpy_s(this->zonaLocuri, strlen(sursa.zonaLocuri) + 1, sursa.zonaLocuri);

	this->nrOcupate = sursa.nrOcupate;

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

	if (this->locuri != nullptr)
	{
		delete[] this->locuri;
		this->locuri = nullptr;
	}

	if (this->zonaLocuri != nullptr)
	{
		delete[] this->zonaLocuri;
		this->zonaLocuri = nullptr;
	}
}

//operator=
Eveniment Eveniment::operator=(const Eveniment& sursa)
{
	delete[] this->titlu;
	this->locuri = nullptr;
	delete[] this->zonaLocuri;

	this->titlu = new char[strlen(sursa.titlu) + 1];
	strcpy_s(this->titlu, strlen(sursa.titlu) + 1, sursa.titlu);

	this->tipEveniment = sursa.tipEveniment;

	this->nrRanduri = sursa.nrRanduri;

	this->nrMaxLocuri = sursa.nrMaxLocuri;
	this->locuri = new int[sursa.nrMaxLocuri];
	for (int i = 0; i < sursa.nrMaxLocuri; i++)
	{
		if (sursa.locuri[i] >= 0)
		{
			this->locuri[i] = sursa.locuri[i];
		}
		else
		{
			this->locuri[i] = 0;
		}
	}

	this->zonaLocuri = new char[strlen(sursa.zonaLocuri) + 1];
	strcpy_s(this->zonaLocuri, strlen(sursa.zonaLocuri) + 1, sursa.zonaLocuri);

	this->nrOcupate = sursa.nrOcupate;

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
	if (nrMaxLocuri > 0)
	{
		this->nrMaxLocuri = nrMaxLocuri;
	}
	else
		throw "Numarul maxim de locuri nu este valid.";
}

void Eveniment::setNrRanduri(int nrRanduri)
{
	if (nrRanduri > 0)
	{
		this->nrRanduri = nrRanduri;
	}
	else
		throw "Numarul de randuri nu este valid.";
}

void Eveniment::setLocuri(int* locuri, int nrMaxLocuri)
{
	if (nrMaxLocuri > 0 && locuri != nullptr)
	{
		this->nrMaxLocuri = nrMaxLocuri;
		this->locuri = new int[nrMaxLocuri];
		for (int i = 0; i < nrMaxLocuri; i++)
		{
			if (locuri[i] >= 0)
			{
				this->locuri[i] = locuri[i];
			}
			else
			{
				this->locuri[i] = 0;
			}
		}
	}
	else
	{
		throw "Invalid.";
	}
}

void Eveniment::setZonaLocuri(const char* zonaLocuri)
{
	if (strlen(zonaLocuri) > 3)
	{
		if (this->zonaLocuri != nullptr)
		{
			delete[] this->zonaLocuri;
		}
		this->zonaLocuri = new char[strlen(zonaLocuri) + 1];
		strcpy_s(this->zonaLocuri, strlen(zonaLocuri) + 1, zonaLocuri);
	}
	else
		throw "Zona este invalida.";
}

void Eveniment::setNrOcupate(int nrOcupate)
{
	this->nrOcupate = nrOcupate;
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

int* Eveniment::getLocuri()
{
	if (locuri != nullptr && nrMaxLocuri > 0)
	{
		int* copie = new int[nrMaxLocuri];
		for (int i = 0; i < nrMaxLocuri; i++)
		{
			copie[i] = locuri[i];
		}
		nrMaxLocuri = nrMaxLocuri;
		return copie;
	}
	else
	{
		locuri = nullptr;
		return locuri;
	}
}

const char* Eveniment::getZonaLocuri()
{
	return this->zonaLocuri;
}

int Eveniment::getNrOcupate()
{
	return this->nrOcupate;
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

	//nrRanduri
	cout << "Introduceti numarul de randuri disponibile la eveniment: " << endl;
	in >> sursa.nrRanduri;
	
	in.ignore();
	//locuri + nrMaxLocuri
	cout << "Introduceti numarul maxim de locuri disponibile la evenimetn: " << endl;
	in >> sursa.nrMaxLocuri;
	delete[] sursa.locuri;
	sursa.locuri = new int[sursa.nrMaxLocuri];
	for (int i = 0; i < sursa.nrMaxLocuri; i++)
	{
		cout << "Dati numarul de locuri: " << i + 1 << endl;
		in >> sursa.locuri[i];
	}

	in.ignore();

	//zonaLocuri
	cout << "Introduceti zona: " << endl;
	char bufferz[200];
	in.getline(bufferz, 200);
	delete[] sursa.zonaLocuri;
	sursa.zonaLocuri = new char[strlen(bufferz) + 1];
	strcpy_s(sursa.zonaLocuri, strlen(bufferz) + 1, bufferz);

	//nrOcupate
	cout << "Introduceti numarul de locuri ocupate: " << endl;
	if (sursa.nrOcupate >= 0)
	{
		in >> sursa.nrOcupate;
	}
	else
		sursa.nrOcupate = 0;

	return in;
}

ostream& operator<<(ostream& out, Eveniment sursa)
{
	out << "Titlu: " << sursa.titlu << endl;
	out << "Eveniment: " << sursa.tipEveniment << endl;
	out << "Numar maxim de locuri disponibile: " << sursa.nrMaxLocuri << endl;
	out << "Numar de randuri disponibile: " << sursa.nrRanduri << endl;
	out << "Acestea sunt locurile disponibile si indisponibile: " << endl;
	for (int i = 0; i < sursa.nrMaxLocuri; i++)
	{
		out << "Locul " << i + 1 << ": " << sursa.locuri[i] << endl;
	}
	out << "Zona: " << sursa.zonaLocuri << endl;
	out << "Sunt ocupate " << sursa.nrOcupate << " locuri." << endl;

	return out;
}

//metoda statica
int Eveniment::getNrEvenimente()
{
	return contorEvenimente;
}

//supraincarcari

//operator de indexare []
int& Eveniment::operator[](int index)
{
	if (index >= 0 && index < this->nrMaxLocuri)
	{
		return this->locuri[index];
	}
	else
	{
		throw new exception();
	}
}

//operator ++ postincrementare
Eveniment& Eveniment::operator++()
{
	this->nrOcupate++;
	return *this;
}

Eveniment Eveniment::operator++(int)
{
	Eveniment copie = *this;
	this->nrOcupate++;
	return copie;
}