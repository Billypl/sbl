#pragma once
template <typename T1, typename T2>
class pair
{

public:

	T1 a;
	T2 b;

	pair			() {};
	pair			(T1 a, T2 b);
	void operator=  (const pair<T1, T2>& other);
	bool operator== (const pair<T1, T2>& other);
	bool operator!= (const pair<T1, T2>& other);
	bool isEqual	(const pair<T1, T2>& other);

	void swap		(pair<T1,T2>& other);
};

