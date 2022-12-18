#include "Ora.h"

//constructor implicit
Ora::Ora()
{
	ora = 00;
	minut = 00;
}

//constructor cu toti parametri
Ora::Ora(int ora, int minut)
{
	if (Ora::oraValida(ora, minut) == true)
	{
		this->ora = ora;
		this->minut = minut;
	}
	else
		throw "Ora introdusa nu este valida.";

}

//constructor de copiere
Ora::Ora(const Ora& sursa)
{
	this->ora = sursa.ora;
	this->minut = sursa.minut;
}

//operator=
Ora& Ora::operator=(const Ora& sursa)
{
	this->ora = sursa.ora;
	this->minut = sursa.minut;

	return *this;
}

//metoda pentru validarea orei
bool Ora::oraValida(int ora, int minut)
{
	bool valid = true;

	if (!(ora >= 0 && ora <= 23))
	{
		valid = false;
	}

	if (!(minut >= 0 && minut <= 59))
	{
		valid = false;
	}

	return valid;

}


//metode de acces
//setteri
void Ora::setOra(int ora)
{
	if (ora >= 0 && ora <= 23)
	{
		this->ora = ora;
	}
	else
	{
		throw "Ora introdusa nu este valida.";
		this->ora = 00;
	}
}

void Ora::setMinut(int minut)
{
	if (minut >= 0 && minut <= 59)
	{
		this->minut = minut;
	}
	else
	{
		throw "Minutul introdus nu este valid.";
		this->minut = 00;
	}
}

//getteri
int Ora::getOra()
{
	return ora;
}

int Ora::getMinut()
{
	return minut;
}

//operatori de citire si de afisare
istream& operator>>(istream& in, Ora& sursa)
{
	cout << "Alegeti ora: " << endl;
	in >> sursa.ora;

	in.ignore();

	cout << "Alegeti minutul: " << endl;
	in >> sursa.minut;

	return in;
}

ostream& operator<<(ostream& out, Ora sursa)
{
	out << "Ora: " << sursa.ora << endl;
	out << "Minutul: " << sursa.minut << endl;

	return out;
}