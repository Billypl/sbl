#pragma once
#include "../hdrs/vector.h"

#pragma once
class string
{
	vector<char> buffer;

public:

	string(){};
	string(const string& other);
	string(const vector<char>& other);
	string(const char* other);

	~string(){};

	size_t		size() const;

	char&		operator[] (size_t index);
	const char& operator[] (size_t index) const;
	string		operator+  (const string& other);
	string		operator+  (const char* other);
	string&		operator=  (const string& other);
	void		operator+= (const string& other);
	void		operator+= (const char& element);
	void		operator+= (const char* str);

	bool		operator== (const string& other);
	bool		operator!= (const string& other);

	const char* cstr	() const;
	void		pop		();
	void		remove	(size_t index);
	void		remove	(size_t start, size_t end);
	void		clear	();
	void		insert	(size_t index, const char& element);
	void		insert	(size_t index, const string& other);
	void		reverse	();
	bool		isEmpty	();
	bool		isEqual	(const string& other);

};

