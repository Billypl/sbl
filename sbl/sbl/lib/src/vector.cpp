#include "../hdrs/vector.h"
#include "../algorithm.h"
#include <cstring>

#define BASIC_VECTOR_CAPACITY 1

template<typename T>
bool vector<T>::isInBounds(size_t index) const
{
	return index < _size;
}

template<typename T>
vector<T>::vector()
	: _size(0), _capacity(BASIC_VECTOR_CAPACITY)
{
	buffer = new T[_capacity];
}

template<typename T>
vector<T>::vector(size_t size)
	: _size(size), _capacity(size)
{
	buffer = new T[_size];
}

template<typename T>
vector<T>::vector(size_t size, const T& element)
	: vector(size)
{
	fill(element);
}

template<typename T>
vector<T>::vector(const vector<T>& other)
{
	_size = other._size;
	_capacity = other._capacity;
	buffer = new T[other._capacity];
	sbl::copy(buffer, other.buffer, other._size);
}

template<typename T>
vector<T>::vector(const T* other, size_t size)
{
	_size = size;
	_capacity = size;
	buffer = new T[size];
	sbl::copy(buffer, other, size);
}

template<typename T>
vector<T>::~vector()
{
	delete[] buffer;
	buffer = nullptr;
}

template<typename T>
size_t vector<T>::size() const
{
	return _size;
}

template<typename T>
size_t vector<T>::capacity() const
{
	return _capacity;
}

template<typename T>
T& vector<T>::operator[](size_t index)
{
	return at(index);
}

template<typename T>
const T& vector<T>::operator[](size_t index) const
{
	return at(index);
}

template<typename T>
vector<T> vector<T>::operator+(const T& element) const
{
	vector<T> tmp(buffer);
	tmp += element;

	return tmp;
}

template<typename T>
vector<T> vector<T>::operator+(const vector<T>& other) const
{
	vector<T> tmp(*this);
	tmp += other;

	return tmp;
}

template<typename T>
vector<T>& vector<T>::operator=(const vector<T>& other)
{
	if(&other != this)
	{
		_size = other._size;
		_capacity = other._capacity;
		delete[] buffer;
		buffer = new T[_capacity];
		sbl::copy(buffer, other.buffer, _size);
	}
	return *this;
}

template<typename T>
void vector<T>::operator+=(const vector<T>& other)
{
	add(other);
}

template<typename T>
void vector<T>::operator+=(const T& element)
{
	add(element);
}

template<typename T>
bool vector<T>::operator==(const vector<T>& other) const
{
	return isEqual(other);
}

template<typename T>
bool vector<T>::operator!=(const vector<T>& other) const
{
	return !isEqual(other);
}

template<typename T>
void vector<T>::add(const T& element)
{
	_size++;
	if (_size > _capacity)
	{
		_capacity *= 2;
		T* tmp = new T[_capacity];
		sbl::copy(tmp, buffer, _size - 1);
		delete[] buffer;
		buffer = tmp;
	}
	buffer[_size-1] = element;
}

template<typename T>
void vector<T>::add(const vector<T>& other)
{
	insert(_size, other);
}

template<typename T>
template<typename ...T2>
void vector<T>::add(T first, T2 ...others)
{
	add(first);
	add(others...);
}

template<typename T>
void vector<T>::pop()
{
	if (_size > 0)
		_size--;
	else
		throw "out of bounds";
}

template<typename T>
void vector<T>::remove(size_t index)
{
	if (!isInBounds(index))
		throw "out of bounds";
	moveItems(1, index);
}

template<typename T>
void vector<T>::remove(size_t start, size_t end)
{
	if (!isInBounds(start) || !isInBounds(end))
		throw "out of bounds";
	if (start > end)
		throw "wrong index";

	const int difference = end - start + 1;
	moveItems(difference, start);
}

template<typename T>
void vector<T>::moveItems(const int difference, const size_t start)
{
	_size -= difference;
	for (int i = 0; i < _size; i++)
		if (i >= start)
			buffer[i] = buffer[i + difference];
}

template<typename T>
void vector<T>::clear()
{
	remove(0, _size - 1);
}

template<typename T>
void vector<T>::insert(size_t index, const T& element)
{
	if(index > _size)
		throw "out of bounds";
	if (isFreeSpace())
		insertElementToCurrentBuffer(element, index);
	else
		insertElementToNewBuffer(index, element);
}

template<typename T>
void vector<T>::insertElementToCurrentBuffer(const T& element, const size_t& index)
{
	T e = element;
	for (int i = 0; i < _size; i++)
	{
		if (i >= index)
		{
			sbl::swap(buffer[i], e);
		}
	}
	buffer[_size] = e;
	_size++;
}

template<typename T>
void vector<T>::insertElementToNewBuffer(const size_t& index, const T& element)
{
	T* tmp = new T[_size + 1];
	vector<T> wrapper(1, element);

	insertVector(index, wrapper, tmp);
	updateData(1, tmp);
}

template<typename T>
void vector<T>::insert(size_t index, const vector<T>& other)
{
	if (index > _size)
		throw "out of bounds";
	T* tmp = new T[_size + other._size];
	insertVector(index, other, tmp);
	updateData(other._size, tmp);
}

template<typename T>
void vector<T>::insertVector(size_t index, const vector<T>& other, T* tmp)
{
	for (int i = 0, j = 0; i < _size + other._size; i++, j++)
	{
		if (i == index)
		{
			for (int m = 0; m < other._size; m++)
			{
				tmp[j] = other.buffer[m];
				j++;
			}
		}
		if (i < _size)
			tmp[j] = buffer[i];
	}
}

template<typename T>
void vector<T>::fill(const T& value)
{
	for (int i = 0; i < _size; i++)
		buffer[i] = value;
}

template<typename T>
void vector<T>::fill(size_t start, const T& value)
{
	if (!isInBounds(start))
		throw "out of bounds";

	for (int i = start; i < _size; i++)
		buffer[i] = value;
}

template<typename T>
void vector<T>::fill(size_t start, size_t end, const T& value)
{
	if (!isInBounds(start) && !isInBounds(start) && start <= end)
		throw "out of bounds";

	for (int i = start; i <= end; i++)
		buffer[i] = value;
	
}

template<typename T>
T& vector<T>::at(size_t index) const
{
	if (!isInBounds(index))
		throw "out of bounds";
	return *(buffer + index);
}

template<typename T>
void vector<T>::reverse()
{
	for(int i = 0; i < _size/2; i++)
		sbl::swap(buffer[_size - i - 1], buffer[i]);
}

template<typename T>
bool vector<T>::isEmpty() const
{
	return _size == 0 ;
}

template<typename T>
bool vector<T>::isEqual(const vector<T>& other) const
{
	if (_size != other._size)
		return false;

	for (int i = 0; i < _size; i++)
		if (buffer[i] != other.buffer[i])
			return false;

	return true;
}

template<typename T> 
const T* vector<T>::buff() const
{
	return buffer;
}

template<typename T>
void vector<T>::reserve(size_t size)
{
	_capacity = size;
	_size = sbl::min(size, _size);
	vector<T> tmp(size);
	for (int i = 0; i < _size; i++)
		tmp[i] = buffer[i];
	buffer = tmp.buffer;
	tmp.buffer = nullptr;
}

template<typename T>
bool vector<T>::isFreeSpace() const
{
	return _size < _capacity;
}

template<typename T>
void vector<T>::updateData(size_t elemSize, T* tmp)
{
	_size += elemSize;
	_capacity = _capacity >= _size ? _capacity : _size;
	delete[] buffer;
	buffer = tmp;
}
