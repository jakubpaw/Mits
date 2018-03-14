#include <iostream>
#include "wektor.h"
#include <conio.h>
using namespace std;
int main()
{
	Wektor wektor1(15);
	while (wektor1.dlugosc > 0)
	{
		cout << wektor1.dlugosc << endl;
		try
		{
			wektor1.zmniejsz(10);
		}
		catch (Wektor w)
		{
			wektor1.dlugosc = 0;
			cout << "wyjatek" << endl;
		}
	}
	cout << wektor1.dlugosc;
	_getch();
	return 0;
}