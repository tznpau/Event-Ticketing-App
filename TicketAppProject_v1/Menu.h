#pragma once
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include "Eveniment.h"
#include "Bilet.h"
#include "User.h"

using namespace std;

class Menu
{
private:
	int admin_sau_user = 0;
	string parola = "1234";
	int alegereUser = 0;
	int alegereAdmin = 0;
	int id = 0;
	
	void adaugaEveniment();
	void stergeEveniment(int);
	void editEveniment(int);

	void adminMenu();
	void adminValid();

	void userMenu();

	vector<Bilet> bilete;
	vector<Eveniment> evenimente;
	vector<User> users;


public:
	//constructor
	Menu();
	//destructor
	~Menu();

	//metode virtuale  publice
	void cumparaBilet();
	void afiseazaBilete();
	void afiseazaEvenimente();
	void afiseazaUsers();

	void start();
};




