#include <iostream>
#include "lib/algorithm.h"
#include "lib/pair.h"
#include "lib/point.h"
#include "lib/vector.h"

using namespace sbl;
using std::cout;

void print(pair<int, int> a)
{
	cout << a.a << " " << a.b << std::endl;
}

int main()
{
	point<int> a(1,2), b(2,1);
	//print(a);
	cout << a.distance(b);
	//cout << sbl::abs(-1);
}

