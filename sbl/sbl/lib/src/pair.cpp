#include "../hdrs/pair.h"
#include "../algorithm.h"

template<typename T1, typename T2>
pair<T1, T2>::pair(T1 a, T2 b)
	: a(a), b(b) {}

template<typename T1, typename T2>
void pair<T1, T2>::operator=  (const pair<T1, T2>& other)
{
	a = other.a;
	b = other.b;
}

template<typename T1, typename T2>
bool pair<T1, T2>::operator==(const pair<T1, T2>& other) const
{
	return isEqual(other);
}

template<typename T1, typename T2>
bool pair<T1, T2>::operator!=(const pair<T1, T2>& other) const
{
	return !isEqual(other);
}

template<typename T1, typename T2>
bool pair<T1, T2>::isEqual(const pair<T1, T2>& other) const
{
	return (a == other.a) && (b == other.b);
}

template<typename T1, typename T2>
void pair<T1, T2>::swap(pair<T1, T2>& other)
{
	sbl::swap(a, other.a);
	sbl::swap(b, other.b);
}



