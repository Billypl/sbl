#pragma once

template <typename T>
class vector
{
	T* buffer = nullptr;
	size_t _capacity;
	size_t _size;

public:

	vector		();
	vector		(size_t size);
	vector		(size_t size, const T& element); // fill constructor
	vector		(const vector<T>& other);
	vector		(const T* other, size_t size);

	~vector();

	size_t		size()								const;  
	size_t		capacity()							const;

	T&			operator[] (size_t index);
	const T&	operator[] (size_t index)			const;
	vector<T>	operator+  (const T	&element)		const;
	vector<T>	operator+  (const vector<T> &other) const;
	vector<T>&	operator=  (const vector<T> &other);
	void		operator+= (const vector<T> &other);
	void		operator+= (const T &element);

	bool		operator== (const vector<T> &other) const;
	bool		operator!= (const vector<T> &other) const;

	void		add		(const T &element);
	void		add		(const vector<T> &other);
						template<typename... T2>
	void		add		(T first, T2... others);
	void		pop		();
	void		remove	(size_t index);
	void		remove	(size_t start, size_t end);
	void		clear	();
	void		insert  (size_t index, const T& element);
	void		insert	(size_t index, const vector<T>& other);
	void		fill	(const T& value);
	void		fill	(size_t start, const T& value);
	void		fill	(size_t start, size_t end, const T& value);
	T&			at		(size_t index)				const;
	void		reverse ();
	bool		isEmpty () const;
	bool		isEqual (const vector<T>& other)	const;
	const		T* buff ()							const;
	void		reserve (size_t size);

private:
	
	bool isInBounds(size_t index)					const;
	bool isFreeSpace()								const;
	void moveItems(const int difference, const size_t start);

	void updateData(size_t elemSize, T* tmp);
	void insertElementToCurrentBuffer(const T& element, const size_t& index);
	void insertElementToNewBuffer(const size_t& index, const T& element);
	void insertVector(size_t index, const vector<T>& other, T* tmp);

};


