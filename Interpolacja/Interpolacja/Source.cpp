#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;

int n;//stopien wielomianu
int np;
double a;
double b;
double*wezly;  //wartosci wezlow
double*wartFunkcjiWezlow; //wartosci funkcji w wezlach

void init()
{
	wezly = new double[n + 1];
	wartFunkcjiWezlow = new double[n + 1];
}

void input()
{
	cout << "Podaj stopien wielomianu" << endl;
	cin >> n;
	cout << endl;
	cout << "Podaj np" << endl;
	cin >> np;
	cout << endl;
	cout << "Podaj dolna granice przedzialu" << endl;
	cin >> a;
	cout << endl;
	cout << "Podaj gorna granice przedzialu" << endl;
	cin >> b;
	cout << endl;
}

void funkcja_tablicujaca_wezly_i_wartosci_funkcji_interpolacji()
{
	double odlegosc = (b - a) / n;//odleglosc miedzy wezlami
	for (int i = 0; i < n + 1; i++)
	{
		wezly[i] = a + i * odlegosc;
		wartFunkcjiWezlow[i] = abs(cos(wezly[i])*wezly[i]);
		cout << wezly[i] << "  -   " << wartFunkcjiWezlow[i] << endl;
	}
}

int main()
{
	init();
	input();
	funkcja_tablicujaca_wezly_i_wartosci_funkcji_interpolacji();
	_getch();
}









//badanie sposobow
//funkcje f(x)
//przezia³y
