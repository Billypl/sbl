#include <iostream>
#include "lib/algorithm.h"
#include "lib/pair.h"
#include "lib/vector.h"

using namespace sbl;
using std::cout;

void print(pair<int, int> a)
{
	cout << a.a << " " << a.b << std::endl;
}

int main()
{
	pair<int, int> a(1,2);
	print(a);

}

