#include <iostream>
#include "lib/algorithm.h"
#include "lib/pair.h"
#include "lib/vector.h"

using namespace sbl;

void vectorTest()
{
	vector<int> a;
	for (int j = 0; j < 10; j++)
	{
		a.add(j);
		for (int i = 0; i < a.size(); i++)
			std::cout << a[i] << " ";

		std::cout << " size: " << a.size() << " capacity: " << a.capacity() << "\n";
	}
}

void print(vector<int> a)
{
	for (int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
}

using std::cout;
int main()
{
	vectorTest();
	/*vector<int> a;
	a.add(9, 9, 9, 9);
	a += 1;
	vector<int> b = a;
	a += 1;
	cout << (a != b);
	a += b;*/
	

}

