#pragma once

template <typename T>
class vector
{
	T* buffer;
	size_t _capacity;
	size_t _size;

public:

	vector();
	vector(size_t size);
	vector(const vector<T>& other);
	~vector();

	size_t	  size();
	size_t	  capacity();

	T&		  operator[] (size_t index);
	vector<T> operator+  (const vector<T> &other);
	void	  operator=  (const vector<T> &other);
	void	  operator+= (const vector<T> &other);
	void	  operator+= (const T &element);

	bool	  operator== (const vector<T> &other);
	bool	  operator!= (const vector<T> &other);

	void pushBack	(const T &element);
	void popBack	();
	T&	 at			(size_t index);
	bool isEmpty	();
};

