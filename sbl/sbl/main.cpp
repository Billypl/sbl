#include <iostream>
#include "lib/algorithm.h"
#include "lib/pair.h"
#include "lib/vector.h"

using namespace sbl;

// test v1.0
void vectorTest()
{
	vector<int> a;
	for (int j = 0; j < 100; j++)
	{
		a.add(j);
		for (int i = 0; i < a.size(); i++)
			std::cout << a[i] << " ";

		std::cout << " size: " << a.size() << " capacity: " << a.capacity() << "\n";
	}
}

using std::string;

/* vector<string> */
void print(vector<string> a) // KOPIA
{
	for (int i = 0; i < a.size(); i++)
		for(int j = 0; j < a[i].size(); j++)
			std::cout << a[i][j] << " ";
}
void printb(vector<string>& a) // ORGINAŁ
{
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < a[i].size(); j++)
			std::cout << a[i][j] << " ";
}

/* vector<vector<int>> */
void print(vector<vector<int>> a) //KOPIA
{
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < a[i].size(); j++)
			std::cout << a[i][j] << " ";
}
void printb(vector<vector<int>>& a) //ORGINAŁ
{
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < a[i].size(); j++)
			std::cout << a[i][j] << " ";
}

/*nie ma znaczenia czy kopia czy orginał*/
void print(vector<int> a)  
{
	for (int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
}
void printb(vector<int>& a)
{
	for (int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
}

using std::cout;
int main()
{

	/* odkomentować interesujący punkt, żeby zobaczyć, co się psuje (zakomentować pozostałe)*/

	/* 1. nie ma znaczenia czy kopia czy orginał*/
	vector<int> a(2, 0);

	/* 2. vector<vector<int>> */
	/*vector<int> b(2, 0);
	vector<vector<int>> a(3, b);*/

	/* 3. vector<string> */
	/*string c = "aaa";
	vector<string> a(3, c);*/
	

	//TODO: FIX
	// when passing vector to a function destructor breaks
	// probably copy constructor malfunction
	//

	printb(a); // funkcja działająca zawsze
	print(a); // funkcja psująca

	/* 
	/  gdy zostawimy niezakomentowaną linijkę print(a);, przy zakończeniu funkcji main() program się wysypuje
	/  problem musi leżeć w konstruktorze kopiującym, bo te dwie funkcje różnią się tylko i wyłącznie sposobem przekazania argumentów do funkcji
	*/
}

