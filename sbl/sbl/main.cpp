#include <iostream>
#include "lib/algorithm.h"
#include "lib/pair.h"

using namespace sbl;


int main()
{
	pair<int> a(1, 2);
	std::cout << a.a << " " << a.b << std::endl;
	a.swap();
	std::cout << a.a << " " << a.b << std::endl;
}