#pragma once

template <typename T>
class point
{

public:

	T x, y;

	point			  () {};
	point			  (T x, T y);
	void   operator=  (const point<T>& other);
	bool   operator== (const point<T>& other);
	bool   operator!= (const point<T>& other);
	bool   isEqual	  (const point<T>& other);

	void swap         ();
	void swap         (point<T>& other);
};

