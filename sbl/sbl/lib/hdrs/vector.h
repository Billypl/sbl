#pragma once

template <typename T>
class vector
{
	T* buffer;
	size_t _capacity;
	size_t _size;

public:

	vector		();
	vector		(size_t size);
	vector		(size_t size, const T& element); // fill constructor
	vector		(const vector<T>& other);

	~vector();

	size_t		size();
	size_t		capacity();

	T&			operator[] (size_t index);
	vector<T>	operator+  (const vector<T> &other);
	void		operator=  (const vector<T> &other);
	void		operator+= (const vector<T> &other);
	void		operator+= (const T &element);

	bool		operator== (const vector<T> &other);
	bool		operator!= (const vector<T> &other);

	void add	(const T &element);
	void add	(const vector<T> &other);
	template<typename... T2>
	void add	(T first, T2... others);
	void pop	();
	void remove	(size_t index);
	void remove	(size_t start, size_t end);
	void insert (size_t index, const T& element);
	void insert	(size_t index, const vector<T>& other);
	void fill	(const T& value);
	void fill	(size_t start, const T& value);
	void fill	(size_t start, size_t end, const T& value);
	T&	 at		(size_t index);
	bool isEmpty();
	bool isEqual(const vector<T>& other);

private:
	
	bool isInBounds(size_t index);

};


