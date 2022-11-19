#pragma once
template <typename T>
class pair
{
public:
	pair() {};
	pair(T a, T b);
	T a, b;
	void swap();
};

