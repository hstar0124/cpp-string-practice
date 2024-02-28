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

String String::Replace(size_t index, size_t len, const char* cstr)
{
	if (index >= _size)
		assert(false);

	size_t newSize = _size - len + StrLen(cstr);
	size_t newCapacity = newSize + 1;

	char* newData = new char[newCapacity];

	StrCpy(newData, _data, index);

	StrCat(newData, cstr);

	StrCat(newData, _data + index + len);

	delete[] _data;
	_data = newData;
	_size = newSize;
	_capacity = newCapacity;

	return *this;
}

int String::Compare(const char* cstr)
{

	size_t len1 = Size();
	size_t len2 = StrLen(cstr);

	// 문자열 길이가 다른 경우
	if (len1 != len2)
		return len1 > len2 ? 1 : -1;

	for (size_t i = 0; i < len1; i++)
	{
		// ASCII 값 차이로 판단
		if (_data[i] != cstr[i])
			return _data[i] > cstr[i] ? 1 : -1;
	}

	// 두 문자열이 같은 경우
	return 0;
	
}

int String::Compare(String str)
{
	return Compare(str._data);
}

size_t String::Copy(char* dest, size_t len, size_t index) const
{
	if (index >= _size)
		return 0;

	size_t copyLen = len < (_size - index) ? len : (_size - index);

	for (size_t i = 0; i < copyLen; i++)
		dest[i] = _data[index + i];

	return copyLen;
}

size_t String::Find(const char* cstr, size_t index)
{
	if (index >= _size)
		return npos;

	if (cstr == nullptr || *cstr == '\0')
		return npos;

	size_t strLength = StrLen(cstr);

	const char* startSearch = _data + index;

	while (*startSearch != '\0') 
	{
		const char* p1 = startSearch;
		const char* p2 = cstr;

		while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2)
		{
			p1++;
			p2++;
		}

		if (*p2 == '\0')
			return startSearch - _data;

		startSearch++;
	}

	return npos;
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
	*dest = '\0';
}

void String::StrCpy(char* dest, const char* src, int index)
{
	for (int i = 0; i < index; i++)
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';
}

void String::StrCat(char* dest, const char* src)
{
	while (*dest != '\0')
		dest++;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';
}

bool String::CheckOutofRange(size_t index) const
{
	return (index >= _size);
}



void String::Print() const
{
	for (int i = 0; i < _size; i++)
	{
		cout << _data[i];
	}
	cout << endl;
}