
#include "awariasamochodu.h"
#include "awariasilnika.h"
#include "awariaswiecy.h"
#include <vector>
#include <iostream>
#include <typeinfo>
#include <conio.h>
using namespace std;
int main()
{
	vector<AwariaSamochodu*>listaAwarii;
	listaAwarii.push_back(new AwariaSamochodu());
	listaAwarii.push_back(new AwariaSilnika());
	listaAwarii.push_back(new AwariaSwiecy());
	listaAwarii.push_back(new AwariaSamochodu());


	for (int i = 0; i < listaAwarii.capacity(); i++)
	{
		try {
			if (typeid(*listaAwarii[i]).name() == typeid(AwariaSamochodu).name())
				throw AwariaSamochodu();
			if (typeid(*listaAwarii[i]).name() == typeid(AwariaSilnika).name())
				throw AwariaSilnika();
			if (typeid(*listaAwarii[i]).name() == typeid(AwariaSwiecy).name())
				throw AwariaSwiecy();
		}
		catch (AwariaSwiecy &AS) { cout << "Awaria swiecy" << endl; }
		catch (AwariaSilnika &AS) { cout << "Awaria silnika" << endl; }
		catch (AwariaSamochodu &AS) { cout << "Awaria samochodu" << endl; }
	}
	_getch();
	return 0;
}