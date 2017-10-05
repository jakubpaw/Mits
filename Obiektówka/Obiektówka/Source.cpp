#include <iostream>
#include <conio.h>
using namespace std;

class Klasa
{
public:
	int blabla;
	void set(int a)
	{
		blabla = a;
	}
	int get()
	{
		return blabla;
	}
};

int main()
{
	Klasa qwerty;
	qwerty.set(15);
	cout << qwerty.get() << endl;
	_getch();
	return 0;
}