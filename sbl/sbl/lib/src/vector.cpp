#include "../hdrs/vector.h"
#include <cstring>

template<typename T>
vector<T>::vector()
{
	_size = 0;
	_capacity = 0;
	buffer = new T[0];
}

template<typename T>
vector<T>::vector(size_t size)
{
	this->_size = _size;
	_capacity = _size;
	buffer = new T[_size];
}


template<typename T>
vector<T>::vector(const vector<T>& other)
{
	_size = other._size;
	_capacity = other._capacity;
	buffer = new T[other._size];
	memcpy(&buffer, &other.buffer, other._size);
}

template<typename T>
vector<T>::~vector()
{
	delete[] buffer;
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
void vector<T>::pushBack(const T& element)
{
	_size++;
	if (_size > _capacity)
	{
		if (_capacity == 0)
			_capacity = 1;

		_capacity *= 2;
		T* tmp = new T[_capacity];
		memcpy(tmp, buffer, _size * sizeof(T));
		delete[] buffer;
		buffer = new T[_capacity];
		memcpy(buffer, tmp, _size * sizeof(T));
		delete[] tmp;
	}
	buffer[_size-1] = element;
}

#include<iostream>
#include <stdexcept>
template<typename T>
T& vector<T>::at(size_t index)
{
	try {
		if (index < _size && index >= 0)
			return *(buffer + index);
		throw "out of bounds";
	}
	catch(char* err){
		
	}
}

template<typename T>
bool vector<T>::isEmpty()
{
	return _size;
}
