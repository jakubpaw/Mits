#include "rekin.h"

Rekin::Rekin(int sWaga, std::string sGatunek, int sDlugosc):Ryba(sWaga,sGatunek),dlugosc(sDlugosc)
{
}
void Rekin::jakaWaga()
{
	cout << "Rekin wa¿y " << waga << " kg" << endl;
}
void Rekin::jakiGatunek()
{
	cout << "Gatunek rekina to " << gatunek << endl;
}
void Rekin::jakaDlugosc()
{
	cout << "Rekin mierzy " << dlugosc << " metrow" << endl;
}