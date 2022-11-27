#pragma once
#include "string.h"
#include <cstdio>

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

	inline char itoc(int x)
	{
		if (x < 0 || x > 9)
			throw "Not a digit";
		return x + '0';
	}

	inline int ctoi(char ch)
	{
		if (ch < '0' || ch > '9')
			throw "Not a number";
		return ch - '0';
	}

	inline int stoi(string str)
	{
		int number = 0;
		for(int i = 0; i < str.size(); i++)
		{
			if(str[i] == ' ' || str[i] == '\n' || str[i] == EOF)
				continue;
			int num = ctoi(str[i]);
			number += num*pow(10, str.size() - i - 1);
		}
		return number;
	}

	inline string itos(int x)
	{
		string number;
		while (x)
		{
			char digit = (x % 10) + '0';
			number += digit;
			x /= 10;
		}
		number.reverse();
		return number;
	}

}
