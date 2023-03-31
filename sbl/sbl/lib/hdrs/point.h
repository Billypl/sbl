#pragma once

template <typename T>
class point
{

public:

	T x, y;

	point			  () {};
	point			  (T x, T y);
	void   operator=  (const point<T>& other);
	bool   operator== (const point<T>& other) const;
	bool   operator!= (const point<T>& other) const;
	bool   isEqual	  (const point<T>& other) const;

	void swap         ();
	void swap         (point<T>& other);
};

class coords : public point<int> 
{ 
public:
	coords() = default;
	using point::point;
};
