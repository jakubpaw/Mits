#include "ryba.h"

Ryba::Ryba(int sWaga, std::string sGatunek):Zwierze(sWaga),gatunek(sGatunek)
{
}
void Ryba::jakaWaga()
{
	cout << "Ryba wa¿y " << waga << " kg" << endl;
}
void Ryba::jakiGatunek()
{
	cout << "Gatunek ryby to " << gatunek << endl;
}


