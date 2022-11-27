#include "../hdrs/string.h"
#include "../vector.h"
#include "../algorithm.h"

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
	for(int i = 0; i < other.size(); i++)
		buffer.add(other[i]);
}

string::string(const char* other)
{
	for(int i = 0; i < strlen(other) + 1; i++)
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
	tmp.insert(buffer.size() - 1, other.buffer);
	return tmp;
}

string string::operator+(const char* other) const
{
	vector<char> tmp(buffer), oth(other, strlen(other) + 1);
	tmp.insert(buffer.size() - 1, oth);
	return tmp;
}

string string::operator+(const char& ch) const
{
	vector<char> tmp(buffer);
	tmp.insert(buffer.size() - 1, ch);
	return tmp;
}

string& string::operator=(const string& other)
{
	buffer = other.buffer;
	return *this;
}

void string::operator+=(const string& other)
{
	buffer.pop();
	buffer += other.buffer;
}

void string::operator+=(const char& element)
{
	buffer.pop();
	buffer += element;
	buffer += '\0';
}

void string::operator+=(const char* str)
{
	vector<char> tmp(str, strlen(str) + 1);
	buffer.pop();
	buffer += tmp;
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
}

void string::remove(size_t index)
{
	buffer.remove(index);
}

void string::remove(size_t start, size_t end)
{
	buffer.remove(start, end);
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

void string::clear()
{
	buffer.clear();
}

void string::insert(size_t index, const char& element)
{
	buffer.insert(index, element);
}

void string::insert(size_t index, const string& other)
{
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

