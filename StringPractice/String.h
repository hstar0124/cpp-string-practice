#pragma once

class String
{
public:
	String();
	String(const char*);
	String(const String&);
	~String();

	size_t GetSize() const;
	size_t GetCapacity() const;
	
	void Print();

private:
	size_t StrLen(const char*);
	void StrCpy(char*, const char*);

private:
	const size_t _npos = -1;
	size_t _size = 0;
	size_t _capacity = 0;
	char* _data;
};

