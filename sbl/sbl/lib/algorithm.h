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
}
