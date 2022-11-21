#include <iostream>
#include "lib/algorithm.h"
#include "lib/pair.h"
#include "lib/vector.h"

using namespace sbl;
using std::cout;

void print(vector<int>& a)
{
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
}

int main()
{
	vector<int> b,a;
	b.add(1, 2, 3);
	b.insert(1, 9);
	a.add(0);
	a.add(0);
	a.insert(1, b);
	a.remove(2);
	//a.clear();

	print(a);
}

