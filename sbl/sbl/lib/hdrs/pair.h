#pragma once
#include <iostream>

template <typename T1, typename T2>
class pair
{

public:

	T1 a;
	T2 b;

	pair			() {};
	pair			(T1 a, T2 b);
	void operator=  (const pair<T1, T2>& other);
	bool operator== (const pair<T1, T2>& other) const;
	bool operator!= (const pair<T1, T2>& other) const;
	bool isEqual	(const pair<T1, T2>& other) const;

	template <typename T1, typename T2>
	friend std::ostream& operator<<(std::ostream& os, const pair<T1, T2>& p);
	void swap		(pair<T1,T2>& other);
};

