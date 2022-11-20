#include "../hdrs/vector.h"
#include "../algorithm.h"
#include <cstring>

template<typename T>
bool vector<T>::isInBounds(size_t index)
{
	return index < _size;
}

template<typename T>
vector<T>::vector()
	: _size(0), _capacity(0)
{
	buffer = new T[0];
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
vector<T>::~vector()
{
	delete[] buffer;
	buffer = nullptr;
}

template<typename T>
size_t vector<T>::size()
{
	return _size;
}

template<typename T>
size_t vector<T>::capacity()
{
	return _capacity;
}

template<typename T>
T& vector<T>::operator[](size_t index)
{
	return at(index);
}

template<typename T>
vector<T> vector<T>::operator+(const vector<T>& other)
{
	size_t newSize = _size + other._size;
	vector<T> tmp(newSize);
	int iter = 0;
	
	for (int i = 0; i < _size; i++)
		tmp.buffer[iter] = buffer[i];
	for (int i = 0; i < other._size; i++)
		tmp.buffer[iter] = other.buffer[i];

	return tmp;
}

template<typename T>
void vector<T>::operator=(const vector<T>& other)
{
	_size = other._size;
	_capacity = other._capacity;
	delete[] buffer;
	buffer = new T[_capacity];
	sbl::copy(buffer, other.buffer, _size);
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
bool vector<T>::operator==(const vector<T>& other)
{
	return isEqual(other);
}

template<typename T>
bool vector<T>::operator!=(const vector<T>& other)
{
	return !isEqual(other);
}

template<typename T>
void vector<T>::add(const T& element)
{
	_size++;
	if (_size > _capacity)
	{
		if (_capacity == 0)
			_capacity = 1;

		_capacity *= 2;
		T* tmp = new T[_capacity];
		sbl::copy(tmp, buffer, _size);
		delete[] buffer;
		buffer = new T[_capacity];
		sbl::copy(buffer, tmp, _size);
		delete[] tmp;
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
	throw "out of bounds";
}

template<typename T>
void vector<T>::remove(size_t index)
{
	if (!isInBounds(index))
		throw "out of bounds";

	T* tmp = new T[_size - 1];
	for (int i = 0, j = 0; i < _size; i++, j++)
	{
		if (i == index)
		{
			j--;
			continue;
		}
		tmp[j] = buffer[i];
	}

	delete[] buffer;
	_size -= 1;
	buffer = new T[_capacity];
	sbl::copy(buffer, tmp, _size);

	delete[] tmp;
}

template<typename T>
void vector<T>::remove(size_t start, size_t end)
{
	if (!isInBounds(start) || !isInBounds(end))
		throw "out of bounds";
	if (start > end)
		throw "wrong index";

	int difference = end - start + 1;
	T* tmp = new T[_size - difference];
	for (int i = 0, j = 0; i < _size; i++, j++)
	{
		if (i >= start && i <= end)
		{
			j--;
			continue;
		}
		tmp[j] = buffer[i];
	}

	delete[] buffer;
	_size -= difference;
	buffer = new T[_capacity];
	sbl::copy(buffer, tmp, _size);

	delete[] tmp;
}

template<typename T>
void vector<T>::insert(size_t index, const T& element)
{
	if (_size <= _capacity)
	{
		T e = element;
		for (int i = 0, j = 0; i < _size; i++, j++)
			if (i >= index)
				sbl::swap(buffer[j], e);
		buffer[_size] = e;
		_size++;
	}
	else
	{
		T* tmp = new T[_size + 1];
		for (int i = 0, j = 0; i < _size; i++, j++)
		{
			if (i == index)
			{
				tmp[j] = element;
				j++;
			}
			tmp[j] = buffer[i];
		}

		delete[] buffer;
		_size += 1;
		_capacity = _capacity >= _size ? _capacity : _size;
		buffer = new T[_capacity];
		sbl::copy(buffer, tmp, _size);

		delete[] tmp;
	}
}

template<typename T>
void vector<T>::insert(size_t index, const vector<T>& other)
{
	T* tmp = new T[_size + other._size];
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

	delete[] buffer;
	_size += other._size;
	_capacity = _capacity >= _size ? _capacity : _size;
	buffer = new T[_capacity];
	sbl::copy(buffer, tmp, _size);

	delete[] tmp;
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
T& vector<T>::at(size_t index)
{
	if (!isInBounds(index))
		throw "out of bounds";
	return *(buffer + index);
}

template<typename T>
bool vector<T>::isEmpty()
{
	return _size;
}

template<typename T>
bool vector<T>::isEqual(const vector<T>& other)
{
	if (_size != other._size)
		return false;

	for (int i = 0; i < _size; i++)
		if (buffer[i] != other.buffer[i])
			return false;

	return true;
}

