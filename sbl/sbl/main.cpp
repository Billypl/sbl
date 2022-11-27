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


int main()
{
	const string s = "test";
    ffile file(s, iosm::read);

	while(true)
	{
		const string name = file.readLine(':');
			if (name == EOT)
			break;
		const int value = file.readInt();
		printf("Name: %s value: %i \n", name.cstr(), value);
	}

}

