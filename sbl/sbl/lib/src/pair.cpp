#include "../hdrs/pair.h"
#include "../algorithm.h"
#include <conio.h>

template<typename T>
pair<T>::pair(T a, T b)
	: a(a), b(b) {}

template<typename T>
void pair<T>::swap()
{
	sbl::swap(a, b);
}

