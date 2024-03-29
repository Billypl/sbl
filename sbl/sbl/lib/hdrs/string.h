#pragma once
#include "../hdrs/vector.h"
#include <iostream>

class string
{
	vector<char> buffer;

public:

	string();
	string(const int& x);
	string(const string& other);
	string(const vector<char>& other);
	string(const char* other);
	string(const char& other);

	~string() {};

	size_t size() const;

	char& operator[] (size_t index);
	const char& operator[] (size_t index) const;
	string operator+ (const string& other) const;
	string operator+ (const char* other) const;
	string operator+ (const char& ch) const;
	string operator+ (const int& num) const;
	string& operator= (const string& other);
	string& operator+= (const string& other);
	string& operator+= (const char& element);
	string& operator+= (const char* str);
	void operator+= (const int& num);

	bool operator== (const string& other) const;
	bool operator== (const char* other) const;
	bool operator== (const char& ch) const;
	bool operator!= (const string& other) const;
	bool operator!= (const char* other) const;
	bool operator!= (const char& ch) const;


	const char* cstr() const;
	void pop();
	void remove(size_t index);
	void remove(size_t start, size_t end);
	void clear();
	void insert(size_t index, const char& element);
	void insert(size_t index, string other);
	void reverse();
	bool isEmpty();
	bool isEqual(const string& other) const;
	bool isEqual(const char* other) const;
	bool isEqual(const char& ch) const;
	string trimStart() const;
	string trimEnd() const;
	string trim() const;
	vector<string> split(char separator);
	static vector<string> split(const string& str, char separator);
	friend std::ostream& operator<<(std::ostream& os, const string& dt);

};

