#include "String.h"
#include <iostream>
#include <cassert>

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
	delete[] _data;
}

size_t String::Size() const
{
	return _size;
}

size_t String::Capacity() const
{
	return _capacity;
}

void String::operator=(const char* cstr)
{
	if (_data)
		delete[] _data;

	_size = StrLen(cstr);
	_capacity = _size + 1;

	_data = new char[_capacity];

	StrCpy(_data, cstr);
}

char& String::operator[](size_t index)
{
	if (CheckOutofRange(index))
		assert(false);

	return _data[index];
}

char String::At(size_t index) const
{
	if (CheckOutofRange(index))
		assert(false);

	return _data[index];
}

char String::Front() const
{
	if (_size == 0)
		assert(false);

	return _data[0];
}

char String::Back() const
{
	if (_size == 0)
		assert(false); 
	
	return _data[_size -1];
}

void String::Resize(size_t newSize)
{
	if (newSize <= _size)
	{
		_size = newSize;
	}
	else
	{
		size_t newCapacity = newSize + 1;
		char* newStr = new char[newCapacity];

		if (_data != nullptr) 
		{
			StrCpy(newStr, _data);
			delete[] _data;
		}


		_data = newStr;
		_size = newSize;
		_capacity = newCapacity;
	}
}

void String::Resize(size_t newSize, char ch)
{
	size_t beforeSize = _size;

	if (newSize <= _size)
	{
		_size = newSize;
	}
	else
	{
		size_t newCapacity = newSize + 1;
		char* newStr = new char[newCapacity];

		if (_data != nullptr)
		{
			StrCpy(newStr, _data);
			delete[] _data;
		}

		_data = newStr;
		_size = newSize;
		_capacity = newCapacity;

		for (size_t i = beforeSize; i < _size; i++)
			_data[i] = ch;
	}
}

void String::ShrinkToFit()
{
	if (_size < _capacity)
	{
		size_t newCapacity = _size + 1;

		if (newCapacity != _capacity)
		{

			char* newStr = new char[newCapacity];
			StrCpy(newStr, _data);
			delete[] _data;

			_data = newStr;
			_capacity = newCapacity;
		}
	}
}

void String::Reserve(size_t newCapacity)
{
	// capacity는 늘어나는 방향으로만 설정 가능
	if (_capacity > newCapacity)
		assert(false);

	char* newStr = new char[newCapacity];
	StrCpy(newStr, _data);
	delete[] _data;

	_data = newStr;
	_capacity = newCapacity;
}

void String::Clear()
{
	size_t newCapacity = _capacity;
	delete[] _data;

	_size = 0;
	_data = new char[_capacity];
}

bool String::Emtpy() const
{
	return _size == 0;
}

String String::SubStr(size_t index, size_t len) const
{
	if (len != npos && (CheckOutofRange(index) || CheckOutofRange(index + len)))
		assert(false);

	if (_size == 0)
		return String();

	size_t substrSize = (len == npos) ? _size - index : len;
	String substr;
	substr.Resize(substrSize);

	for (size_t i = 0; i < substrSize; ++i)
	{
		substr._data[i] = _data[index + i];
	}

	return substr;
}


void String::Print() const
{
	for (int i = 0; i < _size; i++)
	{
		cout << _data[i];
	}
	cout << endl;
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

bool String::CheckOutofRange(size_t index) const
{
	return (index >= _size);
}