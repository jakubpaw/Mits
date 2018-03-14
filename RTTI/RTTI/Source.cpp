#include "rekin.h"
#include <vector>
#include<typeinfo>
#include<conio.h>

int main()
{
	vector<Zwierze*>listaZwierzat;
	listaZwierzat.push_back(new Zwierze(19));
	listaZwierzat.push_back(new Ryba(1,"Szprot")); 
	listaZwierzat.push_back(new Rekin(20, "Rekin Polarny", 4));
	
	Ryba* wskaznik;
	for (int i = 0; i < listaZwierzat.capacity(); i++)
	{
		cout << typeid(*listaZwierzat[i]).name() << endl;
		listaZwierzat[i]->jakaWaga();
		if (wskaznik=dynamic_cast<Ryba*>(listaZwierzat[i]))
			wskaznik->jakiGatunek();
		if (typeid(*listaZwierzat[i])==typeid(Rekin))
			((Rekin*)listaZwierzat[i])->jakaDlugosc();
	}
	_getch();
	return 0;
}