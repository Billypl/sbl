#pragma once
#include <cstdio>
#include "../string.h"

#define EOT '\x3'

struct iosm
{
	static const char* read;
	static const char* write;
	static const char* app;
	static const char* writeAndRead;
	static const char* appAndRead;
};

class ffile
{
	FILE* file = nullptr;

public:

	ffile(){};
	ffile(const char* filename, const char* mode);
	ffile(const string& filename, const char* mode);
	~ffile();

	void open(const char* filename, const char* mode);
	void close();

	void movePos(int offset);
	void setPos(int index);

	void write(char ch);
	void write(int num);
	void write(const char* str);
	void write(const string& str);
	void writeLine(const string& str);


	string	read();
	int		readInt();
	string	readLine(char end = '\0');
	char	readChar();
};

