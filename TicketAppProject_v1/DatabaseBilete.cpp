#include "DatabaseBilete.h"

//salveaza biletele intr-un fisier binar
void DatabaseBilete::salveazaBilet(Bilet& bilet)
{
	ofstream file("bilete.dat", ios::binary | ios::app);

	if (file.is_open())
	{
		file.write(reinterpret_cast<char*>(&bilet), sizeof(Bilet));
		file.close();
	}
	else
	{
		cout << "Eroare. Nu se poate deschide fisierul pentru salvarea biletului." << endl;
	}
}

//citeste biletele dintr-un fisier binar
void DatabaseBilete::afiseazaBilete()
{
	vector<Bilet> bilete;

	ifstream file("bilete.dat", ios::binary);
	if (file.is_open())
	{
		Bilet bilet;

		while (file.read(reinterpret_cast<char*>(&bilet), sizeof(Bilet)))
		{
			bilete.push_back(bilet);
		}
		file.close();
	}
	else
	{
		cout << "Eroare. Nu se poate deschide fisierul pentru citirea biletelor." << endl;
	}
	//return bilete;
}
