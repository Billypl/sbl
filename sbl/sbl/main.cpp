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
		a.pushBack(j);
		for (int i = 0; i < a.size(); i++)
			std::cout << a[i];

		std::cout << " size: " << a.size() << " capacity: " << a.capacity() << "\n";
	}
}


int main()
{
	//vectorTest();

	vector<int> a;
	a.pushBack(1);

	std::cout << a.at(11);
	std::cin.get();
}