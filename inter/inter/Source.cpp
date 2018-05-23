#include <iostream>
#include <cmath>
#include <conio.h>
#include <fstream>
#include <sstream>
using namespace std;

#define pi 3.14159265358979323846

double n;//stopien wielomianu
double np;
double a;
double b;
double wezly[1000];  //wartosci wezlow
double wartFunkcjiWezlow[1000]; //wartosci funkcji w wezlach
double A[1000]; //wspolczynniki A

bool rodzajdobieraniawezlow;

double xp[1000]; //punkty
double fxp[1000];//wartosci w punktach
double Ln[1000];//wielomian newtona w tych punktach

/*void init()
{
	wezly = new double[n + 1];
	wartFunkcjiWezlow = new double[n + 1];
}*/

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
	cout << "0 dla rownoodleglych wezlow, 1 dla dobranych optymalnie" << endl;
	cin >> rodzajdobieraniawezlow;
	cout << endl;
}
void funkcja_tablicujaca_wezly_i_wartosci_funkcji_interpolacji()
{
	double odlegosc = (b - a) / n;//odleglosc miedzy wezlami
	for (int i = 0; i <= n ; i++)
	{
		wezly[i] = a + i * odlegosc;
		wartFunkcjiWezlow[i] = abs(cos(wezly[i])*wezly[i]);
		cout << wezly[i] << "  -   " << wartFunkcjiWezlow[i] << endl;
	}
}
void optymalny_dobor_wezlow()
{
	for (int i = 0; i <= n; i++)
	{
		wezly[i] = ((1.0/2.0)*(a+b)+(1.0/2.0)*(b-a)*cos((2*i+1)/(2*n+2)*pi));
		wartFunkcjiWezlow[i] = abs(cos(wezly[i])*wezly[i]);
		cout << wezly[i] << "  -   " << wartFunkcjiWezlow[i] << endl;
	}
}
double ilorazy_roznicowe(int i,int j)//funkcja wyznaczajaca wspolczynniki wielomianu newtona
{
	if (i == j) return wartFunkcjiWezlow[i];
	return ((ilorazy_roznicowe(i + 1, j) - ilorazy_roznicowe(i, j - 1)) / (wezly[j] - wezly[i]));
}
double L(double x)//Wyznaczanie wartowsci wielomianu Newtona w dowolnym punkcie
{
	double temp;
	double suma = 0;
	double iloczyn;
	for (int i = 0; i <= n; i++)
	{
		iloczyn = 1;
		for (int j = 0; j <= i-1; j++ )
		{
			temp = x - wezly[j];
			iloczyn *= (x - wezly[j]);
		}
		suma += iloczyn*A[i];
	}
	return suma;
}
void zapis()
{
	cout << "xp:     fxp:      Ln:     " << endl;
	for (int i=0; i <= np; i++)
	{
		xp[i] = a + i * (b - a) / np;
		fxp[i] = abs(cos(xp[i])*xp[i]);
		Ln[i] = L(xp[i]);
		cout << xp[i] << "   " << fxp[i] << "   " << Ln[i] << endl;
	}

	//zapis do pliku
	FILE* plik;
	plik = fopen("raport.txt", "w");
	fprintf(plik, "n: np: a: b: równo(0)/opty(1)\n");
	fprintf(plik, "%f %f %f %f %d /n",n,np,a,b,rodzajdobieraniawezlow);
	fprintf(plik, "xp:        fxp:       Ln:\n");
	for (int i = 0; i <= np; i++)
	{
		fprintf(plik, "%f  %f  %f\n", xp[i], fxp[i], Ln[i]);
	}
	fclose(plik);
}
int main()
{
	//init();
	input();
	if (rodzajdobieraniawezlow)
		optymalny_dobor_wezlow();
	else
		funkcja_tablicujaca_wezly_i_wartosci_funkcji_interpolacji();
	for (int i = 0; i <= n; i++)
	{
		A[i] = ilorazy_roznicowe(0, i);
		cout << A[i] << endl;
	}
	zapis();
	_getch();
	return 0;
}

//sprawozdanie
//strona tytulowa
//data wykonania,data oddania sprawozdania
//tresc
//dla wszystkich mozliwych kombinacji (16)
//16 wykresow
//wnioski