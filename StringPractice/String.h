#pragma once

class String
{
public:
	String();
	String(const char*);
	String(const String&);
	~String();

	size_t Size() const;
	size_t Capacity() const;
	
	void operator=(const char*);
	
	char& operator[](size_t);
	char At(size_t) const;
	char Front() const;
	char Back() const;
	void Resize(size_t);
	void Resize(size_t, char);
	void ShrinkToFit();
	void Reserve(size_t);
	void Clear();
	bool Emtpy() const;

	String SubStr(size_t index = 0, size_t len = npos) const;

	void Print() const;

private:
	size_t StrLen(const char*);
	void StrCpy(char*, const char*);
	bool CheckOutofRange(size_t) const;

private:
	static const size_t npos = -1;
	size_t _size = 0;
	size_t _capacity = 0;
	char* _data = nullptr;
};

