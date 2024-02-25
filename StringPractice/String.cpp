#include "String.h"
#include <iostream>
using namespace std;

String::String()
{
}

String::String(const char* cstr)
{
	_size = StrLen(cstr);
	_capacity = _size + 1;

	_data = new char[_capacity];

	StrCpy(_data, cstr);
}

String::String(const String& str) 
{
	_size = str._size;
	_capacity = str._capacity;

	_data = new char[_capacity];
	StrCpy(_data, str._data);
}

String::~String()
{
}

size_t String::GetSize() const
{
	return _size;
}

size_t String::GetCapacity() const
{
	return _capacity;
}

void String::Print()
{
	for (int i = 0; i < _size; i++)
	{
		cout << _data[i];
	}
}

size_t String::StrLen(const char* cstr)
{
	int size = 0;

	if (cstr == nullptr)
		return size;

	while (*cstr != '\0') 
	{
		cstr++;
		size++;
	}

	return size;
}

void String::StrCpy(char* dest, const char* src)
{
	for (int i = 0; i < _size; i++)
	{
		*dest = *src;
		dest++;
		src++;
	}
}
