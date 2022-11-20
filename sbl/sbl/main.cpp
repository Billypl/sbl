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

	
	vector<int> b;
	b.add(1, 2, 3, 4, 5);
	b.insert(1, 9);
	b.remove(3, 4); 

	print(b);

}

