#define _CRT_SECURE_NO_WARNINGS
#include "../hdrs/ffile.h"
#include "../vector.h"
#include "../algorithm.h"

const char* iosm::read = "r";
const char* iosm::write = "w";
const char* iosm::app = "a";
const char* iosm::writeAndRead = "w+"; // creates new file
const char* iosm::appAndRead = "a+";

ffile::ffile(const char* filename, const char* mode)
{
	open(filename, mode);
}

ffile::ffile(const string& filename, const char* mode)
{
	open(filename.cstr(), mode);
}

ffile::~ffile()
{
	close();
}


void ffile::open(const char* filename, const char* mode)
{
	file = fopen(filename, mode);
}

void ffile::close()
{
	if(file != nullptr)
		fclose(file);
}

void ffile::write(const char* str)
{
	fputs(str, file);
}

void ffile::write(const string& str)
{
	fputs(str.cstr(), file);
}

void ffile::writeLine(const string& str)
{
	fputs(str.cstr(), file);
	fputc('\n', file);
}

void ffile::movePos(int offset)
{
	fseek(file, offset, SEEK_CUR);
}

void ffile::setPos(int index)
{
	fseek(file, index, SEEK_SET);
}

bool ffile::eof()
{
	return feof(file);
}

bool ffile::operator==(const FILE* other) const
{
	return file == other;
}

void ffile::write(char ch)
{
	fputc(ch, file);
}

void ffile::write(int num)
{
	fputs(sbl::itos(num).cstr(), file);
}

string ffile::read()
{
	return readLine(' ');
}

int ffile::readInt()
{
	return sbl::stoi(read());
}

string ffile::readLine(char end)
{
	string chars;
	bool isFirstChar = true;
	int ch;

	while(true)
	{
		ch = fgetc(file);
		if(ch < 0 || ((ch == '\n' || ch == end) && !isFirstChar))
			break;
		isFirstChar = false;

		chars += char(ch);
	}

	if (chars.isEmpty() && ch == EOF)
		chars = EOT;
		
	return chars;
}
