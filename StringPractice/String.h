#pragma once

template<typename T>
class MyIterator
{
public:
	MyIterator();
	MyIterator(T* ptr);
	~MyIterator();

	void operator++() { ptr++; }
	void operator++(int) { ++ptr; }
	T& operator*() { return *ptr; }
	bool operator==(const MyIterator& other) { return ptr == other.ptr; }
	bool operator!=(const MyIterator& other) { return ptr != other.ptr; }

private:
	T* ptr;
};

template<typename T>
inline MyIterator<T>::MyIterator()
	: ptr(nullptr)
{
}

template<typename T>
inline MyIterator<T>::MyIterator(T* ptr)
	: ptr(ptr)
{
}

template<typename T>
inline MyIterator<T>::~MyIterator()
{
}


class String
{
public:
	String();
	String(const char*);
	String(const String&);
	~String();

	typedef MyIterator<char> iterator;
	iterator Begin() { return iterator(_data); }
	iterator End() { return iterator(_data + _size); }

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
	String Replace(size_t index, size_t len, const char*);
	int Compare(const char*);
	int Compare(String);
	size_t Copy(char* dest, size_t len, size_t index = 0) const;
	size_t Find(const char* cstr, size_t index = 0);

	void PushBack(char c);
	void PopBack();

	void Print() const;

private:
	size_t StrLen(const char*);
	void StrCpy(char*, const char*);
	void StrCpy(char*, const char*, int);
	void StrCat(char*, const char*);
	bool CheckOutofRange(size_t) const;

private:
	static const size_t npos = -1;
	size_t _size = 0;
	size_t _capacity = 0;
	char* _data = nullptr;
};

