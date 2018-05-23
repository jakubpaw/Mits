#include <iostream>
#include <math.h>
#include <fstream>
#include <stdio.h>
#include <conio.h>

using namespace std;

string nazwa_pliku="Jacobi6.txt";

int it;//liczba iteracji
int n;//rozmiar macierzy

double eps;//dok³adnoœæ
int MLI;//maksymalna liczba iteracji
double norma;//norma


//macierze i wektory
double**A;
double*B;
double**alpha;
double*beta;
double*X;
double*Xnext;



bool a()
{
	//wczytanie rozmiaru, dok³adnoœci i maksymalnej liczby iteracji
	cout << "Podaj n: ";
	cin >> n;
	cout << endl;
	cout << "Podaj eps: ";
	cin >> eps;
	cout << endl;
	cout << "Podaj MLI: ";
	cin >> MLI;
	cout << endl;

//	utworzenie macierzy a
	A = new double*[n];
	for (int i = 0; i < n; i++)
	{
		A[i] = new double[n];
	}
	//utworzenie wektora
	B = new double[n];

	//otworzenie pliku
	ifstream plik(nazwa_pliku);
	if (!plik.good())
	{
		cout << "blad";
		return false;
	}
	//wczytanie macierzy A z pliku
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			plik >> A[i][j];
	//wczytanie wektora B z pliku
	for (int i = 0; i < n; i++)
		plik >> B[i];

	//zamkniecie pliku
	plik.close();
	return true;
}

bool b()
{//utworzenie macierzy alpha
	alpha = new double*[n];
	for (int i = 0; i < n; i++)
	{
		alpha[i] = new double[n];
	}
	//utworzenie wektora beta
	beta = new double[n];

	for (int i = 0; i < n; i++) 
	{
		//sprawdzenie czy nie wystepuje dzielenie przez 0
		if (A[i][i] == 0) {
			cout << "dzielenie przez 0 dla i = " << i << endl;
			return false;
		}
		else
		{
			//obliczenie wartosci elementow macierzy alpha
			for (int j = 0; j < n; j++)
			{
				if (i == j) alpha[i][j] = 0;
				else
				{
					alpha[i][j] = -A[i][j] / A[i][i];
				}
			}
			//obliczenie wartosci elementow wektora beta
			beta[i] = B[i] / A[i][i];
		}
	}
	return true;
}
void c()
{
	X = new double[n];//wektor wynikow poprzedniej iteracji
	Xnext = new double[n];//wektor wynikow aktualnej iteracji
	it = 0;
	//ustawienie wektora beta jako pierwszego wektora aktualnej iteracji
	for (int i = 0; i < n; i++)
	{
		Xnext[i] = beta[i];
	}
	double suma;
	//pêtla iteracji
	do
	{
		//inkrementacja licznika
		it++;
		//przepisanie wynikow do drugiego wektora
		for (int i = 0; i < n; i++)
		{
			X[i] = Xnext[i];
		}
		//wyznaczenie nowego wektora wynikow
		for (int i = 0; i < n; i++)
		{
			suma = 0;
			for (int j = 0; j < n; j++)
			{
				suma += alpha[i][j] * X[j];
			}
			Xnext[i] = suma;
		}
		for (int i = 0; i < n; i++)
			Xnext[i] += beta[i];

		norma = 0;
		//obliczenie normy
		for (int i = 0; i < n; i++)
		{
			if (abs(X[i] - Xnext[i]) > norma)
				norma = abs(X[i] - Xnext[i]);
		}
	} while (norma > eps && it < MLI);//warunek stopu


}
void d()
{
	//otworzenie pliku raport.txt
	FILE * plik;
	plik = fopen("raport.txt", "w");
	//zapis do pliku macierzy A
	fprintf(plik, "A;\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			fprintf(plik, "%f ", A[i][j]);

		fprintf(plik, "\n");
	}
	//zapis do pliku wektora B
	fprintf(plik, "B: \n");
	for (int i = 0; i < n; i++)
		fprintf(plik, "%f ", B[i]);
	fprintf(plik, "\n");
	//zapis do pliku eps
	fprintf(plik, "Dok³adnoœæ: \n");
	fprintf(plik, "%f ",eps);
	fprintf(plik, "\n");
	//zapis do pliku MLI
	fprintf(plik, "MLI: \n");
	fprintf(plik, "%d ", MLI);
	fprintf(plik, "\n");
	//zapis do pliku macierzy alpha
	fprintf(plik, "alpha: \n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			fprintf(plik, "%f ", alpha[i][j]);

		fprintf(plik, "\n");
	}
	//zapis do pliku wektora beta
	fprintf(plik, "beta: ");
	for (int i = 0; i < n; i++)
		fprintf(plik, "%f ", beta[i]);
	fprintf(plik, "\n");
	//zapis do pliku wektora wynikow
	fprintf(plik, "WYNIK: ");
	for (int i = 0; i < n; i++)
		fprintf(plik, "\n%1.10e ", Xnext[i]);
	fprintf(plik, "\n");
	//zapis do pliku wektora przedostatniej iteracji
	fprintf(plik, "Wektor przedostatniej iteracji: ");
	for (int i = 0; i < n; i++)
		fprintf(plik, "\n%1.10e", X[i]);
	fprintf(plik, "\n");
	//zapis do pliku liczby wykonanych iteracji
	fprintf(plik, "Liczba wykonanych iteracji: %d", it);

	fclose(plik);
}
int main()
{
	if (a())
	{
		if (b())
		{
			c();
			d();
			cout << abs(Xnext[0] - 1) << endl;
			cout << abs(Xnext[1] - 1) << endl;
			cout << abs(Xnext[2]) << endl;
			cout << abs(Xnext[3] +1 ) << endl;
			cout << abs(Xnext[4] +1 ) << endl;
		}
	}
	_getch();
}