#pragma once
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include "Bilet.h"

using namespace std;

//clasa abstracta

class DatabaseBilete
{
public:
	void salveazaBilet(Bilet& bilet);
	void afiseazaBilete();

};

