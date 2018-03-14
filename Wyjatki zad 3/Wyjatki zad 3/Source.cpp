#include "mojaKlasa.h"
#include <conio.h>

int main()
{
	try
	{
		try
		{
			MojaKlasa mmm;
			throw 90;
		}
		catch (int i)
		{
			cout << "blad " << i << endl;
			if (i == 90)
				throw;
		}
	}
	catch (int i)
	{
		cout << "blad krytyczny" << endl;
	}
	_getch();
	return 0;
}