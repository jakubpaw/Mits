#include <iostream>
#include <ctime>
#include <list>
#include <conio.h>
using namespace std;
void print_list(const list<int>& l)
{
	for (auto x : l)
		cout << x << " ";
	cout << endl;
}
int main()
{
	srand(time(NULL));
	list<int> l1;
	for (int i = 0; i < 50; i++)
	{
		l1.push_back(rand() % 50);
	}
	print_list(l1);

	l1.sort();
	l1.unique();
	print_list(l1);
	cout << "Rozmiar listy: " << l1.size() << endl;
	l1.emplace(++l1.begin(), 0);

	print_list(l1);

	_getch();
}