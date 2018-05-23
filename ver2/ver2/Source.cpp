#include <iostream>
#include <math.h>
#include <fstream>
#include <conio.h>

using namespace std;

string nazwa_pliku = "Jacobi1.txt";

int it;
int n;
double eps;
int MLI;
double norma;

double**A;
double*B;
double**alpha;
double*beta;
double*X;
double*Xnext;

double* alpha_x()
{
	double suma;
	for (int i = 0; i < n; i++)
	{
		suma = 0;
		for (int j = 0; j < n; j++)
		{
			suma += alpha[i][j] * X[j];
		}
		Xnext[i] = suma;
	}
	return Xnext;
}

bool a()
{
	cout << "Podaj n: ";
	cin >> n;
	cout << endl;
	cout << "Podaj eps: ";
	cin >> eps;
	cout << endl;
	cout << "Podaj MLI: ";
	cin >> MLI;
	cout << endl;

	A = new double*[n];
	for (int i = 0; i < n; i++)
	{
		A[i] = new double[n];
	}
	B = new double[n];

	for (int i = 0; i < n; i++)
	{
		B[i] = 1;
		for (int j = 0; j < n; j++)
			A[i][j] = 1;
	}
	ifstream plik(nazwa_pliku);
	if (!plik.good())
	{
		cout << "blad";
		return false;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			plik >> A[i][j];
	for (int i = 0; i < n; i++)
		plik >> B[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << A[i][j];
		cout << endl;
	}
	for (int i = 0; i < n; i++)
		cout << B[i];
	cout << endl;
	plik.close();
	return true;
}

bool b()
{
	alpha = new double*[n];
	for (int i = 0; i < n; i++)
	{
		alpha[i] = new double[n];
	}
	beta = new double[n];

	for (int i = 0; i < n; i++)
	{
		if (A[i][i] == 0) {
			cout << "dzielenie przez 0 dla i = " << i << endl;
			return false;
		}
		else
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j) alpha[i][j] = 0;
				else
				{
					alpha[i][j] = -A[i][j] / A[i][i];
				}
			}
			beta[i] = B[i] / A[i][i];
		}
	}
	return true;
}
void c()
{
	X = new double[n];
	Xnext = new double[n];
	it = 0;
	for (int i = 0; i < n; i++)
	{
		Xnext[i] = beta[i];
	}
	do
	{
		for (int i = 0; i < n; i++)
			cout << Xnext[i] << " ";
		it++;
		for (int i = 0; i < n; i++)
		{
			X[i] = Xnext[i];
		}
		alpha_x();
		for (int i = 0; i < n; i++)
			Xnext[i] += beta[i];

		norma = 0;
		for (int i = 0; i < n; i++)
		{
			if (abs(X[i] - Xnext[i]) > norma)
				norma = abs(X[i] - Xnext[i]);
		}

		cout << "norma: " << norma << endl;
		cout << "it: " << it << endl;
	} while (norma > eps && it <= MLI);
	cout << "wyniki" << endl;
	for (int i = 0; i < n; i++)
		cout << Xnext[i] << " ";

}
bool d()
{
	ofstream plik("raport.txt");
	if (!plik.good())
	{
		cout << "blad" << endl;
		return false;
	}
	double i = 0.00000120312012312;
	char ii[] = (char)(i);
	plik << "A: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			plik << A[i][j] << " ";
		}
		plik << endl;
	}
	plik << "B: " << endl;
	for (int i = 0; i < n; i++)
		plik << B[i] << endl;

	plik << "alpha: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			plik << alpha[i][j] << " ";
		}
		plik << endl;
	}

	plik << "beta: " << endl;
	for (int i = 0; i < n; i++)
		plik << beta[i] << endl;

	plik << "WYNIK: " << endl;
	for (int i = 0; i < n; i++)
		plik << Xnext[i] << endl;

	plik << "Wektor przedostatniej iteracji: " << endl;
	for (int i = 0; i < n; i++)
		plik << X[i] << endl;

	plik << "Liczba wykonanych iteracji: " << it << endl;
	plik.close();
}
int main()
{
	if (a())
	{
		if (b())
		{
			c();
			d();
		}
	}
	_getch();
}