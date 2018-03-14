#pragma once
#include<vector>
#include"complex.h"
template<class T, int maxEl>
class Set
{
	T* elements;
	int current_size;
public:
	Set();
	~Set();
	void add(const T&element);
	vector<T> to_vector();
};
template <class T,int maxEl>
Set<T, maxEl>::Set()
{
	elements = new T[maxEl];
	current_size = 0;
}
template<class T,int maxEl>
Set<T, maxEl>::~Set()
{
	delete[] elements;
}
template<class T,int maxEl>
void Set<T, maxEl>::add(const T&element)
{
	if (current_size == maxEl) 
	{ 
		cout << "tablica jest pe³na" << endl; 
		return;
	}
	for (int i = 0; i < current_size;i++)
		if (elements[i] == element)
		{
			cout << "istnieje ju¿ taki element" << endl;
			return;
		}
	elements[current_size] = element;
	current_size++;
}
template<class T, int maxEl>
vector<T> Set<T, maxEl>::to_vector()
{
	vector<T> myVect;
	for (int i = 0; i < current_size; i++)
	{
		myVec.pushback(elements[i]);
	}
}//