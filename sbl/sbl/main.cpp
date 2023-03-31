#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "lib/algorithm.h"
#include "lib/pair.h"
#include "lib/point.h"
#include "lib/vector.h"
#include "lib/string.h"
#include "lib/ffile.h"
#include <cstdio>

using namespace sbl;
using std::cout;
using std::endl;

void vectorTest();
void fileTest();

int main()
{
	vectorTest();
}

template<typename T>
void printVec(vector<T> v)
{
	for (int i  = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

void vectorTest()
{
	vector<int> a;
	a.add(1, 2, 3, 4);
	vector<int> b(a);
	cout << "a: "; printVec(a);
	a.pop();
	a.remove(0);
	a.insert(1, 69);
	cout << "a: "; printVec(a);
	vector<int> c = a + b;
	cout << "b: "; printVec(b);
	cout << "c: "; printVec(c);

}

void fileTest()
{

	const string s = "test.txt";
	ffile file(s, iosm::read);

	while(!file.eof())
	{
		const string name = file.readLine(':');
		const int value = file.readInt();
		printf("Name: %s value: %i \n", name.cstr(), value);
	}

}
