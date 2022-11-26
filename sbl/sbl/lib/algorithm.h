#pragma once

namespace sbl
{
	template<typename T>
	void swap(T& a, T& b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}

	template<typename T>
	void copy(T* dst, const T* src, size_t size)
	{
		for (int i = 0; i < size; i++)
			dst[i] = src[i];
	}

	template<typename T>
	T abs(const T& a)
	{
		return a > 0 ? a : -a;
	}

	template<typename T>
	double pow(T a, int x)
	{
		if (x < 0)
			throw "invalid x";

		double result = 1;
		for (int i = 0; i < x; i++)
			result *= a;

		return result;
	}



}
