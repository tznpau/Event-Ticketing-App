#include "Data.h"

//constructor implicit
Data::Data()
{
	zi = 0;
	luna = 0;
	an = 2023;
}

//constructor cu toti parametrii
Data::Data(int zi, int luna, int an)
{
	if (Data::dataValida(zi, luna, an) == true)
	{
		this->zi = zi;
		this->luna = luna;
		this->an = an;
	}
	else
	{
		throw "Data introdusa nu este valida.";
		this->zi = 0;
		this->luna = 0;
		this->an = 2023;
	}
}

//constructor de copiere
Data::Data(const Data& sursa)
{
	this->zi = sursa.zi;
	this->luna = sursa.luna;
	this->an = sursa.an;
}

//operator=
Data Data::operator=(const Data& sursa)
{
	this->zi = sursa.zi;
	this->luna = sursa.luna;
	this->an = sursa.an;

	return *this;
}

//metoda pentru validarea datei
bool Data::dataValida(int zi, int luna, int an)
{
	bool valid = true;

	if (!(an >= 1950 && an <= 2050))
	{
		valid = false;
	}

	if (zi < 1)
	{
		valid = false;
	}

	switch (luna)
	{
		//luna are 31 zile
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		if (zi > 31)
			valid = false;
		break;

		//luna are 30 zile
	case 4: case 6: case 9: case 11:
		if (zi > 30)
			valid = false;
		break;

		//luna este februarie - verificare an bisect
	case 2:
		if (an % 4 == 0)
		{
			if (zi > 29)
			{
				valid = false;
			}
		}
		else
			if (zi > 28)
			{
				valid = false;
			}
		break;

		//luna nu este intre 1 si 12
	default:
		valid = false;
		break;
	}

	return valid;
}


//metode de acces
//setteri
void Data::setZi(int zi)
{
	if (zi >= 1)
	{
		if (Data::getLuna() == 1 || Data::getLuna() == 3 || Data::getLuna() == 5 || Data::getLuna() == 7 || Data::getLuna() == 8 || Data::getLuna() == 10 || Data::getLuna() == 12)
		{
			if (zi > 31)
			{
				throw "Ziua introdusa nu este valida.";
				this->zi = 0;
			}
		}

		if (Data::getLuna() == 4 || Data::getLuna() == 6 || Data::getLuna() == 9 || Data::getLuna() == 11)
		{
			if (zi > 30)
			{
				throw "Ziua introdusa nu este valida.";
				this->zi = 0;
			}
		}

		if (Data::getLuna() == 2)
		{
			if (Data::getAn() % 4 == 0)
			{
				if (zi > 29)
				{
					throw "Ziua introdusa nu este valida pentru anul respectiv.";
					this->zi = 0;
				}
			}
			else
				if (zi > 28)
				{
					throw "Ziua introdusa nu este valida pentru luna respectiva.";
					this->zi = 0;
				}
		}

		this->zi = zi;
	}
	else
	{
		cout << "Ziua introdusa nu este valida." << endl;
		this->zi = 0;
	}
}

void Data::setLuna(int luna)
{
	if (luna >= 1 && luna <= 12)
	{
		if (luna == 2)
		{
			if (Data::getAn() % 4 == 0)
			{
				if (Data::getZi() > 29)
				{
					cout << "Luna introdusa nu este valida pentru ziua respectiva." << endl;
					cout << "Alege o alta luna sau modifica ziua." << endl;
					this->luna = 0;
				}
			}
			else if (Data::getZi() > 28)
			{
				cout << "Luna introdusa nu este valida pentru ziua respectiva." << endl;
				cout << "Alege o alta luna sau modifica ziua." << endl;
				this->luna = 0;
			}
		}

		this->luna = luna;
	}
	else
	{
		cout << "Luna introdusa nu este valida." << endl;
		this->luna = 0;
	}
}

void Data::setAn(int an)
{
	if (!(an >= 1950 && an <= 2050))
	{
		this->an = an;
	}
	else
	{
		cout << "Anul introdus nu este valid." << endl;
		this->an = 2023;
	}
}

//getteri
int Data::getZi()
{
	return zi;
}

int Data::getLuna()
{
	return luna;
}

int Data::getAn()
{
	return an;
}

//operatori de citire si de afisare
istream& operator>>(istream& in, Data& sursa)
{
	cout << "Alegeti ziua: " << endl;
	in >> sursa.zi;

	in.ignore();

	cout << "Alegeti luna: " << endl;
	in >> sursa.luna;

	in.ignore();

	cout << "Alegeti anul: " << endl;
	in >> sursa.an;

	return in;
}

ostream& operator<<(ostream& out, Data sursa)
{
	out << "Zi: " << sursa.zi << endl;
	out << "Luna: " << sursa.luna << endl;
	out << "An: " << sursa.an << endl;

	return out;
}