#pragma once
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <regex>

using namespace std;

enum CategorieUser {Adult, Elev, Student, Pensionar};

class User
{
private:
	const int idUser = 0;
	static int contorUsers;
	char* nume;
	char* prenume;
	string email;
	CategorieUser categorie;
	int varsta;

public:
	//constructori
	User();
	User(const char*, const char*, string, CategorieUser, int);
	User(const User& sursa);

	//destructor
	~User();

	//metode de acces
	//setteri
	void setNume(const char*);
	void setPrenume(const char*);
	void setEmail(string);
	void setCategorie(CategorieUser);
	void setVarsta(int);

	//getteri
	char* getNume();
	char* getPrenume();
	string getEmail();
	CategorieUser getCategorieUser();
	int getVarsta();

	//metode
	CategorieUser alegeCategorie(string categorie);
	//metoda de validare a adresei de email introduse
	bool emailValid(string&);
	//metoda statica
	static int getNrUsers();

	//operator=
	User& operator=(const User& sursa);

	//operatori de citire si de afisare
	friend istream& operator>>(istream& in, User& sursa);
	friend ostream& operator<<(ostream& out, User sursa);

	//alti operatori
	User operator++(int);
	bool operator==(const User& sursa);
};

