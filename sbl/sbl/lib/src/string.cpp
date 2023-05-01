#include "../hdrs/string.h"
#include "../vector.h"
#include "../algorithm.h"
#include <iostream>

string::string()
{
	buffer.add('\0');
}

string::string(const int& x)
{
	buffer = sbl::itos(x).buffer;
}

string::string(const string& other)
{
	buffer = other.buffer;
}

string::string(const vector<char>& other)
{
	for (int i = 0; i < other.size(); i++)
		buffer.add(other[i]);
}

string::string(const char* other)
{
	for (int i = 0; i < strlen(other) + 1; i++)
		buffer.add(other[i]);
}

string::string(const char& ch)
{
	buffer.add(ch);
	buffer.add('\0');
}

size_t string::size() const
{
	return buffer.size() - 1;
}

char& string::operator[](size_t index)
{
	return buffer[index];
}
const char& string::operator[](size_t index) const
{
	return buffer[index];
}

string string::operator+(const string& other) const
{
	vector<char> tmp(buffer);
	tmp.pop();
	tmp.insert(buffer.size() - 1, other.buffer);
	return tmp;
}

string string::operator+(const char* other) const
{
	vector<char> tmp(buffer), oth(other, strlen(other) + 1);
	tmp.pop();
	tmp.insert(buffer.size() - 1, oth);
	return tmp;
}

string string::operator+(const char& ch) const
{
	vector<char> tmp(buffer);
	tmp.pop();
	tmp += ch;
	tmp += '\0';
	return tmp;
}

string string::operator+(const int& num) const
{
	vector<char> tmp(buffer);
	tmp.pop();
	tmp.insert(buffer.size() - 1, sbl::itos(num).buffer);
	return tmp;
}

string& string::operator=(const string& other)
{
	buffer = other.buffer;
	return *this;
}

string& string::operator+=(const string& other)
{
	buffer.pop();
	buffer += other.buffer;
	return *this;
}

string& string::operator+=(const char& element)
{
	buffer.pop();
	buffer += element;
	buffer += '\0';
	return *this;
}

string& string::operator+=(const char* str)
{
	vector<char> tmp(str, strlen(str) + 1);
	buffer.pop();
	tmp[tmp.size() - 1] = '\0';
	buffer += tmp;
	return *this;
}

void string::operator+=(const int& num)
{
	*this += sbl::itos(num);
}

bool string::operator==(const string& other) const
{
	return isEqual(other);
}

bool string::operator==(const char* other) const
{
	return isEqual(other);

}

bool string::operator==(const char& ch) const
{
	return isEqual(ch);
}

bool string::operator!=(const string& other) const
{
	return !isEqual(other);
}

bool string::operator!=(const char* other) const
{
	return !isEqual(other);

}

bool string::operator!=(const char& ch) const
{
	return !isEqual(ch);
}


const char* string::cstr() const
{
	return buffer.buff();
}

void string::pop()
{
	buffer.pop();
	buffer[buffer.size() - 1] = '\0';
}

void string::remove(size_t index)
{
	buffer.remove(index);
}

void string::remove(size_t start, size_t end)
{
	size_t indx = start + (buffer.size() - end) - 1;
	buffer.remove(start, end);
	if (buffer[buffer.size() - 1] != '\0')
		buffer += '\0';
}

bool string::isEqual(const string& other) const
{
	return buffer == other.buffer;
}

bool string::isEqual(const char* other) const
{
	string tmp(other);
	return buffer == tmp.buffer;
}

bool string::isEqual(const char& ch) const
{
	return (size() == 1 && buffer[0] == ch);
}

string string::trimStart() const
{
	string tmp = (*this);
	while (isspace(tmp.buffer[0]))
		tmp.remove(0);
	return tmp;
}

string string::trimEnd() const
{
	string tmp = (*this);
	while (isspace(tmp[sbl::max(int(tmp.size() - 1), 0)]))
		tmp.pop();
	return tmp;
}

string string::trim() const
{
	string tmp = (*this);
	tmp = tmp.trimStart();
	tmp = tmp.trimEnd();
	return tmp;
}

vector<string> string::split(char separator)
{
	return string::split((*this), separator);
}

vector<string> string::split(const string& str, char separator)
{
	vector<string> result;
	string tmp;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == separator)
		{
			result.add(tmp);
			tmp.clear();
		}
		else
			tmp += str[i];
	}
	result.add(tmp);
	return result;
}

void string::clear()
{
	buffer.clear();
	buffer.add('\0');
}

void string::insert(size_t index, const char& element)
{
	buffer.insert(index, element);
}

void string::insert(size_t index, string other)
{
	other.buffer.pop();
	buffer.insert(index, other.buffer);
}

void string::reverse()
{
	buffer.pop();
	buffer.reverse();
	buffer.add('\0');
}

bool string::isEmpty()
{
	return size() == 0;
}

std::ostream& operator<<(std::ostream& os, const string& str)
{
	std::cout << str.cstr();
	return os;
}
