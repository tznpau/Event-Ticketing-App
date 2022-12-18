#include "User.h"

//initializarea variabilei statice
int User::contorUsers = 0;

//constructor implicit
User::User() : idUser(User::contorUsers++)
{
	this->nume = new char[strlen("N/A") + 1];
	strcpy_s(this->nume, strlen("N/A") + 1, "N/A");

	this->prenume = new char[strlen("N/A") + 1];
	strcpy_s(this->prenume, strlen("N/A") + 1, "N/A");

	this->email = "N/A";

	this->categorie = Adult;

	this->varsta = 0;
}

//constructor cu toti parametri
User::User(const char* nume, const char* prenume, string email, CategorieUser categorie, int varsta) : idUser(User::contorUsers++)
{
	if (strlen(nume) > 2)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}
	else
	{
		this->nume = new char[strlen("N/A") + 1];
		strcpy_s(this->nume, strlen("N/A") + 1, "N/A");
	}

	if (strlen(prenume) > 2)
	{
		this->prenume = new char[strlen(prenume) + 1];
		strcpy_s(this->prenume, strlen(prenume) + 1, prenume);
	}
	else
	{
		this->prenume = new char[strlen("N/A") + 1];
		strcpy_s(this->prenume, strlen("N/A") + 1, "N/A");
	}

	if (User::emailValid(email) == true)
	{
		this->email = email;
	}
	else
	{
		this->email = "N/A";
		cout << "Email-ul nu este valid." << endl;
	}

	if (categorie >= 0 && categorie <= 3)
	{
		this->categorie = categorie;
	}

	if (varsta >= 13 && varsta <= 100)
	{
		this->varsta = varsta;
	}
	else
		this->varsta = 0;
}

//constructor de copiere
User::User(const User& sursa) : idUser(User::contorUsers++)
{
	this->nume = new char[strlen(sursa.nume) + 1];
	strcpy_s(this->nume, strlen(sursa.nume) + 1, sursa.nume);

	this->prenume = new char[strlen(sursa.prenume) + 1];
	strcpy_s(this->prenume, strlen(sursa.prenume) + 1, sursa.prenume);

	this->email = sursa.email;

	this->categorie = sursa.categorie;

	this->varsta = sursa.varsta;

}


//destructor
User::~User()
{
	if (this->nume != nullptr)
	{
		delete[] this->nume;
		this->nume = nullptr;
	}
	if (this->prenume != nullptr)
	{
		delete[] this->prenume;
		this->prenume = nullptr;
	}

	User::contorUsers--;
}

//metoda de validare a emailului introdus
bool User::emailValid(string& email)
{
	//definirea expresiei
	const regex model
	("(\\w+)(\\. | _) ? (\\w*)@(\\w + )(\\.(\\w + )) +");

	//potrivirea stringului email cu modelul expresiei
	return regex_match(email, model);
}


//metode de acces
//setteri
void User::setNume(const char* nume)
{
	if (strlen(nume) > 2)
	{
		delete[] this->nume;
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}
}

void User::setPrenume(const char* prenume)
{
	if (strlen(prenume) > 2)
	{
		delete[] this->prenume;
		this->prenume = new char[strlen(prenume) + 1];
		strcpy_s(this->prenume, strlen(prenume) + 1, prenume);
	}
}

void User::setEmail(string email)
{
	if (User::emailValid(email) == true)
	{
		this->email = email;
	}
}

void User::setCategorie(CategorieUser categorie)
{
	if (categorie >= 0 && categorie <= 3)
	{
		this->categorie = categorie;
	}
}

void User::setVarsta(int)
{
	if (varsta >= 13 && varsta <= 100)
	{
		this->varsta = varsta;
	}
}

//getteri

char* User::getNume()
{
	return this->nume;
}

char* User::getPrenume()
{
	return this->prenume;
}

string User::getEmail()
{
	return this->email;
}

CategorieUser User::getCategorieUser()
{
	return this->categorie;
}

int User::getVarsta()
{
	return this->varsta;
}

//operator=
User& User::operator=(const User& sursa)
{
	delete[] this->nume;
	delete[] this->prenume;
	
	this->nume = new char[strlen(sursa.nume) + 1];
	strcpy_s(this->nume, strlen(sursa.nume) + 1, sursa.nume);

	this->prenume = new char[strlen(sursa.prenume) + 1];
	strcpy_s(this->prenume, strlen(sursa.prenume) + 1, sursa.prenume);

	this->email = sursa.email;

	this->categorie = sursa.categorie;

	this->varsta = sursa.varsta;

	return *this;
}

//operatori de citire si de afisare
istream& operator>>(istream& in, User& sursa)
{
	//nume
	cout << "Completati cu numele utilizatorului: " << endl;
	char buffern[200];
	in.getline(buffern, 200);
	delete[] sursa.nume;
	sursa.nume = new char[strlen(buffern) + 1];
	strcpy_s(sursa.nume, strlen(buffern) + 1, buffern);

	//prenume
	cout << "Completati cu prenumele utilizatorului: " << endl;
	char bufferp[200];
	in.getline(bufferp, 200);
	delete[] sursa.prenume;
	sursa.prenume = new char[strlen(bufferp) + 1];
	strcpy_s(sursa.prenume, strlen(bufferp) + 1, bufferp);

	//email
	cout << "Completati cu email-ul utilizatorului: " << endl;
	char buffere[250];
	in.getline(buffere, 250);
	sursa.email = buffere;

	//categorie user
	int auxCategorie;
	cout << "Selecteaza categoria utilizatorului: " << endl;
	in >> auxCategorie;
	if ((auxCategorie >= 0) && (auxCategorie <= 3))
	{
		sursa.categorie = (CategorieUser)auxCategorie;
	}

	//varsta
	cout << "Alegeti varsta utilizatorului: " << endl;
	in >> sursa.varsta;

	return in;
}

ostream& operator<<(ostream& out, User sursa)
{
	out << "Nume: " << sursa.nume << endl;
	out << "Prenume: " << sursa.prenume << endl;
	out << "Email: " << sursa.email << endl;
	out << "Cateogrie: " << sursa.categorie << endl; //enum o sa afiseze numarul in loc de valoarea in sine; trebuie sa ma gandesc la un casting -> string
	out << "Varsta: " << sursa.varsta << endl;

	return out;
}

//metoda de extragere a valorilor din enum (categoria userilor)
CategorieUser User::alegeCategorie(string categorie)
{
	if (categorie == "Adult")
	{
		return (CategorieUser)0;
	}
	else if (categorie == "Elev")
	{
		return (CategorieUser)1;
	}
	else if (categorie == "Student")
	{
		return (CategorieUser)2;
	}
	else if (categorie == "Pensionar")
	{
		return (CategorieUser)3;
	}
	else
		cout << "Categorie invalida." << endl;
}