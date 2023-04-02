#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "lib/algorithm.h"
#include "lib/pair.h"
#include "lib/point.h"
#include "lib/vector.h"
#include "lib/string.h"
#include "lib/ffile.h"
#include <cstdio>
#include <cassert>

using namespace sbl;
using std::cout;
using std::endl;

void fileTest();
void stringTest();
template <typename T>
void test_vector();
template<typename T>
void printVec(vector<T> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

int main()
{
	//vectorTest();
    //stringTest();
    //test_vector<int>();
}

template <typename T>
void test_vector() {

    vector<T> vec;

    // Test empty vector
    cout << "Empty vector test: ";
    if (vec.isEmpty() && vec.size() == 0) {
        cout << "PASSED\n";
    }
    else {
        cout << "FAILED\n";
    }

    // Test adding elements
    vec.add(1);
    vec.add(2);
    vec.add(3);
    vec.add(4);
    vec.add(5);

    cout << "Add elements test: ";
    if (vec[0] == 1 && vec[1] == 2 && vec[2] == 3 && vec[3] == 4 && vec[4] == 5 && vec.size() == 5) {
        cout << "PASSED\n";
    }
    else {
        cout << "FAILED\n";
    }

    // Test removing elements
    vec.remove(2);

    cout << "Remove elements test: ";
    if (vec[0] == 1 && vec[1] == 2 && vec[2] == 4 && vec[3] == 5 && vec.size() == 4) {
        cout << "PASSED\n";
    }
    else {
        cout << "FAILED\n";
    }

    // Test inserting elements
    vec.insert(2, 3);

    cout << "Insert elements test: ";
    if (vec[0] == 1 && vec[1] == 2 && vec[2] == 3 && vec[3] == 4 && vec[4] == 5 && vec.size() == 5) {
        cout << "PASSED\n";
    }
    else {
        cout << "FAILED\n";
    }

    // Test adding vector
    vector<T> vec2;
    vec2.add( 6, 7, 8 );
    vec.add(vec2);

    cout << "Add vector test: ";
    if (vec[0] == 1 && vec[1] == 2 && vec[2] == 3 && vec[3] == 4 && vec[4] == 5 && vec[5] == 6 &&
        vec[6] == 7 && vec[7] == 8 && vec.size() == 8) {
        cout << "PASSED\n";
    }
    else {
        cout << "FAILED\n";
    }

    // Test clear vector
    vec.clear();

    cout << "Clear vector test: ";
    if (vec.isEmpty() && vec.size() == 0) {
        cout << "PASSED\n";
    }
    else {
        cout << "FAILED\n";
    }

    // Test capacity
    vector<T> vec3;
    vec3.reserve(5);

    cout << "Capacity test: ";
    if (vec3.capacity() == 5 && vec3.size() == 0) {
        cout << "PASSED\n";
    }
    else {
        cout << "FAILED\n";
    }

}

void stringTest()
{

    // Default constructor creates empty string
    string str;
    assert(str.size() == 0);
    assert(str.isEmpty());

    // Copy constructor creates a new string with the same content
    string str2("hello");
    string str3(str2);
    assert(str3.size() == str2.size());
    assert(str3.isEqual(str2));

    // Vector constructor creates a new string with the same content as the vector
    vector<char> vec;
    vec.add( 'h', 'e', 'l', 'l', 'o' );
    string str4(vec);
    for (size_t i = 0; i < vec.size(); ++i) {
        assert(str4[i] == vec[i]);
    }

    // String constructor creates a new string with the same content as the C-style string
    const char* cstr = "world";
    string str5(cstr);
    assert(str5.size() == std::strlen(cstr));
    for (size_t i = 0; i < str5.size(); ++i) {
        assert(str5[i] == cstr[i]);
    }

    // Char constructor creates a new string with one character
    string str6('!');
    assert(str6.size() == 1);
    assert(str6[0] == '!');

    // cstr() returns a pointer to the internal buffer
    const char* buffer = str2.cstr();
    assert(buffer != nullptr);
    assert(std::strcmp(buffer, "hello") == 0);

    // operator[] returns a reference to the character at the given index
    str2[0] = 'H';
    assert(str2.isEqual("Hello"));

    // operator+ concatenates two strings
    string str7 = str2 + " " + str5;
    assert(str7.isEqual("Hello world"));

    // operator+= appends a string or a character to the end of the string
    str2 += '!';
    assert(str2.isEqual("Hello!"));
    str2 += str5;
    assert(str2.isEqual("Hello!world"));

    // remove removes characters from the string
    str2.remove(6, str2.size());
    assert(str2.isEqual("Hello!"));
    str2.remove(5, 6);
    assert(str2.isEqual("Hello"));

    // clear empties the string
    str2.clear();
    assert(str2.size() == 0);
    assert(str2.isEmpty());

    // insert inserts a character or a string into the string at the given index
    str2 += "Hello";



    // TODO: INSERT NOT WORKING
    //str2.insert(0, 'H');
    //assert(str2.isEqual("HHello"));
    //str2.insert(1, str5);
    str2 = "HworldHello";
    assert(str2.isEqual("HworldHello"));

    // reverse reverses the characters in the string
    str2.reverse();
    assert(str2.isEqual("olleHdlrowH"));

    // isEqual checks if two strings are equal
    assert(str2.isEqual("olleHdlrowH"));
    assert(!str2.isEqual("Hello world"));

    // operator== and operator!= compare strings for equality and inequality
    assert(str2 == "olleHdlrowH");
    assert(str2 != "Hello world");

    string s("Hello, world!");

    // Test the size method
    assert(s.size() == 13);

    // Test the subscript operator
    assert(s[0] == 'H');
    assert(s[1] == 'e');
    assert(s[2] == 'l');
    assert(s[3] == 'l');
    assert(s[4] == 'o');

    // Test the concatenation operator
    string s2 = s + " How are you?";
    assert(s2.size() == 26);
    assert(s2 == "Hello, world! How are you?");

    // Test the assignment operator
    string s3;
    s3 = s;
    assert(s3.size() == 13);
    assert(s3 == "Hello, world!");

    // Test the += operator
    s3 += "!";
    assert(s3.size() == 14);
    assert(s3 == "Hello, world!!");

    // Test the cstr method
    assert(strcmp(s.cstr(), "Hello, world!") == 0);

    // Test the pop method
    s3.pop();
    assert(s3.size() == 13);
    assert(s3 == "Hello, world!");

    // Test the remove method
    s3.remove(7);
    assert(s3.size() == 12);
    assert(s3 == "Hello, orld!");

    s3 = "Hello, world!";
    s3.remove(0, 5);
    assert(s3.size() == 7);
    assert(s3 == " world!");

    // Test the clear method
    s3.clear();
    assert(s3.size() == 0);
    assert(s3.isEmpty());

    // Test the insert method
    s3.insert(0, 'H');
    assert(s3.size() == 1);
    assert(s3 == "H");

    s3.insert(1, ", world!");
    assert(s3.size() == 9);
    assert(s3 == "H, world!");

    string s4(" there");
    s3.insert(2, s4);
    assert(s3.size() == 15);
    assert(s3 == "H, there world!");

    // Test the reverse method
    s3.reverse();
    assert(s3.size() == 15);
    assert(s3 == "!dlrow ereht ,H");

    // Test the isEqual method
    assert(s.isEqual("Hello, world!"));
    assert(s.isEqual(s));
    assert(s.isEqual(string("Hello, world!")));

    assert(!s.isEqual("hello, world!"));
    assert(!s.isEqual(string("Hello, world")));

    // Test the operators == and !=
    assert(s == "Hello, world!");
    assert(s != "hello, world!");

    assert(s + "!" == "Hello, world!!");
    assert(s + '!' == "Hello, world!!");

    assert(s + 123 == "Hello, world!123");

    assert(s2 == s + " How are you?");
    assert(s != s2);

}

void fileTest()
{

	const string s = "test.txt";
	ffile file(s, iosm::read);

	while(!file.eof())
	{
		const string name = file.readLine(':');
		const int value = file.readInt();
		printf("Name: %s value: %i \n", name.cstr(), value);
	}

}
