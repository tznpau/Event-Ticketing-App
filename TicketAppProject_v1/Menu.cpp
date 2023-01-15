#include "Menu.h"

//constructor
Menu::Menu()
{

}


//destructor
Menu::~Menu()
{

}

void Menu::cumparaBilet()
{
	//...
	cout << "Ati cumparat un bilet." << endl;
}

void Menu::afiseazaBilete()
{
	//...
	cout << "Biletele sunt urmatoarele: " << endl;
	for (int i = 0; i < bilete.size(); i++)
	{
		cout << bilete[i] << endl;
	}
}


void Menu::afiseazaEvenimente()
{
	cout << "Evenimentele sunt urmatoarele: " << endl;
	for (int i = 0; i < evenimente.size(); i++)
	{
		cout << evenimente[i] << endl;
	}
}

void Menu::afiseazaUsers()
{
	cout << "Userii sunt urmatorii: " << endl;
	for (int i = 0; i < users.size(); i++)
	{
		cout << users[i] << endl;
	}
}


//functii evenimente
void Menu::adaugaEveniment()
{
	cout << "Adauga un eveniment nou" << endl;
}

void Menu::stergeEveniment(int id)
{
	//...
	cout << "Evenimentul a fost sters." << endl;
}

void Menu::editEveniment(int id)
{
	//...
	cout << "Evenimentul a fost modificat." << endl;
}


//functie afisare meniu
void Menu::start()
{
	cout << "*****************************************************" << endl;
	cout << "********************Ticketing App********************" << endl;
	cout << "*****************************************************" << endl;
	cout << endl;
	cout << "Pentru inceput, selectati optiunea de logare: " << endl;
	cout << endl;
	cout << "[1] Admin" << endl;
	cout << "[2] User/Client" << endl;
	cout << endl;
	cout << "*****************************************************" << endl;
	cout << "*****************************************************" << endl;
	cout << "*****************************************************" << endl;
	
	cin >> admin_sau_user;

	switch (admin_sau_user)
	{
	case 1:
		adminValid();
		break;

	case 2:
		userMenu();
		break;

	default:
		cout << "Selectie invalida." << endl;
		start();
		break;
	}
}


//functii user (client)
void Menu::userMenu()
{
	cout << endl;
	cout << "Selectati dintre urmatoarele optiuni: " << endl << endl;
	cout << "[1] Afiseaza evenimentele disponibile" << endl;
	cout << "[2] Afiseaza biletele disponibile" << endl;
	cout << "[3] Cumpara bilete" << endl;
	cout << "[4] Inapoi" << endl;

	cin >> alegereUser;

	switch (alegereUser)
	{
	case 1:
		afiseazaEvenimente();
		break;

	case 2:
		afiseazaBilete();
		break;

	case 3:
		cumparaBilet();
		break;

	case 4:
		start();
		break;

	default:
		cout << "Selectie invalida." << endl;
		userMenu();
		break;
	}
}

//functii admin
void Menu::adminValid()
{
	string parolaIntrodusa;
	system("cls");
	cout << "Pentru a accesa contul de admin, introduceti parola: " << endl;
	cin >> parolaIntrodusa;

	if (parolaIntrodusa == parola)
	{
		adminMenu();
	}
	else
	{
		cout << "Parola introdusa nu este valida." << endl;
		adminValid();
	}

}

void Menu::adminMenu()
{
	cout << endl;
	cout << "Selectati dintre urmatoarele optiuni: " << endl << endl;
	cout << "[1] Adauga eveniment" << endl;
	cout << "[2] Sterge eveniment" << endl;
	cout << "[3] Editeaza eveniment" << endl;
	cout << "[4] Inapoi" << endl;

	cin >> alegereAdmin;

	switch (alegereAdmin)
	{
	case 1:
		adaugaEveniment();
		break;

	case 2:
		stergeEveniment(id);
		break;

	case 3:
		editEveniment(id);
		break;

	case 4:
		start();
		break;

	default:
		cout << "Selectie invalida." << endl;
		adminMenu();
		break;
	}
}


