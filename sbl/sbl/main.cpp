#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "lib/algorithm.h"
#include "lib/pair.h"
#include "lib/point.h"
#include "lib/vector.h"
#include "lib/string.h"
#include <cstdio>

using namespace sbl;
using std::cout;


int main()
{
    string test = "lol";
    cout << (test + "Los").cstr() << '\n';
	
    cout << test.cstr() << '\n';

    string s1 = " s1";
    test += s1;
    cout << test.cstr() << '\n';

    test += 'A';
    cout << test.cstr() << '\n';

    test += "_IT IS MAGIC_";
    cout << test.cstr() << '\n';

    
}

