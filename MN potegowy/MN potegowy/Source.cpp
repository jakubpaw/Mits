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
	cout << "stopien wielomianu = ";
	cin >> m;
	cout<<endl;
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
	x = new double[lw];
	f = new double[lw];
	aa = new double[m+1];
	R = new double[m+1];
	G = new double*[m+1];
	for (int i = 0; i < m+1; i++)
		G[i] = new double[m+1];
	U = new double*[m + 1];
	for (int i = 0; i < m + 1; i++)
		U[i] = new double[m + 1];
	L = new double*[m + 1];
	for (int i = 0; i < m + 1; i++)
		L[i] = new double[m + 1];
	X = new double[m + 1];
	Y = new double[m + 1];
}
void GeneratorTablicy()
{
	double x_temp = a;
	double odstep = (abs(a - b)) / (lw - 1);
	for (int i = 0; i < lw; i++)
	{
		x[i] = x_temp;
		x_temp += odstep;
		f[i] = sin(x[i]);
	}
}
void GeneratorMacierzyG()
{
	for (int j = 0; j < m + 1; j++)
	{
		for (int k = 0; k < m + 1; k++)
		{
			G[j][k] = 0;
			for (int i = 0; i < lw; i++)
				G[j][k]+=pow(x[i],j+k);
		}
	}
}
void GeneratorWektoraR()
{
	for (int k = 0; k < m + 1; k++)
	{
		R[k] = 0;
		for (int i = 0; i < lw; i++)
			R[k] += pow(x[i], k)*f[i];
	}
}
void WartosciFunkcjiAproksymujacej() // funkcja obliczajaca wartosc funkcji aproksymowanej w punktach
{
	for (int i = 0; i <lw; i++)
	{
		aa[i] = 0;
		for (int j = 0; j <= m ; j++)
			aa[i] += X[j] * pow(x[i], j);
	}
}
void wartfaprox()
{
	for (size_t i = 0; i <lw; i++)
	{
		aa[i] = 0;
		for (size_t j = 0; j <=m; j++)
		{
			aa[i] += X[j] * pow(x[i], j);
		}
	}
}


void ObliczanieBledu()
{
	double temp;
	for (int i = 0; i < lw; i++)
	{
		temp = 0;
		for (int j = 0; j < m; j++)
		{
			temp += aa[j] * pow(x[i], j);
		}
		blad += pow(f[i] - temp, 2);
	}
	blad = sqrt(blad / (lw + 1));
}
bool UL()
{
	for (int i = 0; i < m; i++)//ustawianie macierzy UL
	{
		for (int j = 0; j < m; j++) 
		{
			U[i][j] = G[i][j];
			L[i][j] = 0; 
		} 
	}
	for (int i = 0; i < m; i++)
	{
		if (U[i][i] == 0) return false;
		L[i][i] = 1;
	}
	for (int k = 0; k<m-1; k++) {
		for (int i = k + 1; i < m; i++) 
		{
			if (U[k][k] == 0) return false;//dzielenie przez 0
			L[i][k]=U[i][k]/U[k][k]; // obliczanie macierzy L 
			for(int j=k+1;j<m;j++) 
			{ 
				U[i][j]=U[i][j] - ((U[i][k]*U[k][j])/U[k][k]); // obliczanie macierzy U 
			} 
			U[i][k]=0; 
		} 
	}
}void rozwiazmacierz() // rozwiazanie macierzy trojkatynychgornych 
{ 
	Y[0] = R[0];
	for( int i= 1; i<m; i++) 
	{ 
		double suma=0.0;
		for(int k=1; k<=i-1; k++)
			suma+=L[i][k]* Y[k]; 
		Y[i]=R[i] - suma;
	} X[m]= Y[m] / U[m][m]; 
	for (int i=m-1; i>=0; i--) 
	{ 
		double suma=0.0; 
		for(int k= i+1; k<=m; k++) 
			suma+=U[i][k]*X[k]; 
		X[i]=(Y[i]- suma) / U[i][i]; 
	} 
}
void zapis()
{
	cout << blad << endl;
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
		rozwiazmacierz();
		//WartosciFunkcjiAproksymujacej();
		wartfaprox();
		ObliczanieBledu();
		zapis();
	}
	else cout << "blad przy tworzeniu mecierzy U lub L" << endl;
	_getch();
	return 0;
}


//lw=50
//przedzia³ <-2.0,2.0>
//cos(x)*cos(2x)
//zwiekszamy stopien wielomianu aproksymacyjnego od 1 do 20, podajac wartosc bledu za kazdym razem
//i wybieramy stopien z najmniejszym bledem
//dla stopnia optymalnego podajemy uzyskane wartosci wspó³czynnikow
//nastepnie przy ustalonym stopniu optymalnym co najmniej 3 razy zmieniamy pozostale parametr
//czyli szerokosc przedzialu aproksymacji
//polozenie przedzialu aproksymacji, oraz liczbe wezlow.
//Rysujemy co najmniej 1 wykres z dok³adnym przebiegiem funkcji oraz kilka jego przybli¿eñ
