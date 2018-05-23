#include <iostream>
#include<cmath>
#include<conio.h>

using namespace std;
int m; //stopieñ wielomianu
double a; //dolna granica przedzia³u testowego
double b; //górna granica przedzia³u testowego
int lw; //liczba wêz³ów
double blad;// obliczana wartosc bledu

double* x;//tablica argumentow
double* f;//tablica wartosci funkcji aproksymowanej
double* aa;//tablica wartosci wspolczynnikow a0,a1...an wielomianu Qm

double** G;
double** U;
double** L;
double* R;
double*X;
double*Y;

void pobierz()
{
	// pobranie od u¿ytkownika stopnia wielomianu, granic przedzialu i liczby wezlow
	cout << "stopien wielomianu = ";
	cin >> m;
	cout << endl;
	cout << "dolna granica przedzialu = ";
	cin >> a;
	cout << endl;
	cout << "gorna granica przedzialu = ";
	cin >> b;
	cout << endl;
	cout << "liczba wezlow = ";
	cin >> lw;
	cout << endl;
}
void Init()
{
	//inicjacja wszystkich potrzebnych macierzy i wektorów
	x = new double[lw];
	f = new double[lw];
	aa = new double[lw];
	R = new double[m + 1];
	G = new double*[m + 1];
	for (int i = 0; i < m + 1; i++)
		G[i] = new double[m + 1];
	U = new double*[m + 1];
	for (int i = 0; i < m + 1; i++)
		U[i] = new double[m + 1];
	L = new double*[m + 1];
	for (int i = 0; i < m + 1; i++)
		L[i] = new double[m + 1];
	X = new double[m + 1];
	Y = new double[m + 1];
}
void GeneratorTablicy() //wygenerowanie tablicy x i f
{
	double x_temp = a;
	double odstep = (abs(a - b)) / (lw - 1);
	for (int i = 0; i < lw; i++)
	{
		x[i] = x_temp;
		x_temp += odstep;
		f[i] = cos(x[i])*cos(2*x[i]);
	}
}
void GeneratorMacierzyG() //obliczanie wartosci macierzy G
{
	for (int j = 0; j < m + 1; j++)
	{
		for (int k = 0; k < m + 1; k++)
		{
			G[j][k] = 0;
			for (int i = 0; i < lw; i++)
				G[j][k] += pow(x[i], j + k);
		}
	}
}
void GeneratorWektoraR() //obliczanie wartosci wektora R
{
	for (int k = 0; k < m + 1; k++)
	{
		R[k] = 0;
		for (int i = 0; i < lw; i++)
			R[k] += pow(x[i], k)*f[i];
	}
}
bool UL() // obliczanie macierzy U i L
{
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			U[i][j] = G[i][j]; 
			L[i][j] = 0;
		}
	}
	for (int i = 0; i <= m; i++)
	{
		L[i][i] = 1;
		if (U[i][i] == 0) //zwracamy false, jesli na przek¹tnej znajduje siê 0
		{
			cout << "0 na przekatnej, i = " << i << endl;
			return false;
		}
	}
	for (int k = 0; k<m; k++)
	{
		for (int i = k + 1; i <= m; i++)
		{
			if (U[k][k] == 0) 
			{
				cout << "dzielenie przez 0, k = " << k << endl;
				return false;
			}// zwracamy false jeœli wystapuje dzielenie przez 0
			L[i][k] = U[i][k] / U[k][k]; // obliczanie macierzy L
			for (int j = k + 1; j <= m; j++) // obliczanie macierzy U
			{
				U[i][j] = U[i][j] - ((U[i][k] * U[k][j]) / U[k][k]);
			}
			U[i][k] = 0;
		}
	}
	return true;
}
void RozwiazMacierz() //rozwiazanie macierzy trojkatnogornych
{
	Y[0] = R[0];
	for (int i = 1; i <= m; i++)
	{
		double suma = 0.0;
		for (int k = 0; k <= i - 1; k++)
			suma += L[i][k] * Y[k];
		Y[i] = R[i] - suma;
	}
	X[m] = Y[m] / U[m][m];
	for (int i = m - 1; i >= 0; i--)
	{
		double suma = 0.0;
		for (int k = i + 1; k <= m; k++)
			suma += U[i][k] * X[k];
		X[i] = (Y[i] - suma) / U[i][i];
	}
}
void WartFAprox() // obliczanie wartosci funkcji aproksymowanej
{
	for (int i = 0; i < lw; i++)
	{
		aa[i] = 0;
		for (int j = 0; j <= m; j++)
			aa[i] += X[j] * pow(x[i], j);
	}
}
void ObliczanieBledu()
{
	double temp = 0;
	for (int i = 0; i <lw; ++i)
		temp += pow(aa[i] - f[i], 2);
	blad = sqrt(temp / lw);

}
void zapis() //tworzenie raportu w pliku txt
{
	FILE * plik;
	plik = fopen("raport.txt", "w");

	fprintf(plik, "stopien wielomianu: %d\n", m);
	fprintf(plik, "ilosc wezlow: %d\n", lw);
	fprintf(plik, "dolna granica przedzialu: %f\n", a);
	fprintf(plik, "gorna granica przedzialu: %f\n", b);
	fprintf(plik, "wartosci wspolczynnikow:\n");

	for (size_t i = 0; i < m + 1; i++)
	{
		fprintf(plik, "%2.10f\n", X[i]);
	}

	fprintf(plik, "wezel		wartosc funkcji	wartosc funkcji aproksymujacej\n");

	for (size_t i = 0; i <lw; i++)
	{
		fprintf(plik, "%2.10f	%2.10f	%2.10f\n", x[i], f[i], aa[i]);
	}
}
int main()
{
	pobierz();
	Init();
	GeneratorTablicy();
	GeneratorMacierzyG();
	GeneratorWektoraR();
	if (UL())
	{
		RozwiazMacierz();
		WartFAprox();
		ObliczanieBledu();
		zapis();
	}
	else cout << "blad przy tworzeniu mecierzy U lub L" << endl;
	_getch();
	return 0;
}