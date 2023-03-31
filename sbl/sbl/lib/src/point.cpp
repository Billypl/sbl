#include "../hdrs/point.h"
#include "../algorithm.h"

template<typename T>
point<T>::point(T x, T y)
	: x(x), y(y) {}

template<typename T>
inline void point<T>::operator=(const point<T>& other)
{
	x = other.x;
	y = other.y;
}

template<typename T>
inline bool point<T>::operator==(const point<T>& other) const
{
	return isEqual(other);
}

template<typename T>
inline bool point<T>::operator!=(const point<T>& other) const
{
	return !isEqual(other);
}

template<typename T>
inline bool point<T>::isEqual(const point<T>& other) const
{
	return (x == other.x) && (y == other.y);
}

template<typename T>
void point<T>::swap()
{
	sbl::swap(x, y);
}

template<typename T>
void point<T>::swap(point<T>& other)
{
	sbl::swap(x, other.x);
	sbl::swap(y, other.y);
}
