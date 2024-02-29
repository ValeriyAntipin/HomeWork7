#pragma once
#include <iostream>
#include <exception>
#include <algorithm>
using namespace std;

class bad_range final : public exception {
public:
	virtual const char* what() const noexcept override { return "RANGE ERROR!"; }
};

class bad_length final : public exception {
public:
	virtual const char* what() const noexcept override { return "LENGTH ERROR!"; }
};

class IntegerArray {
private:
	int _length;
	int* _data;
public:
	IntegerArray() = default;
	IntegerArray(int lenght);
	~IntegerArray();
	void erase();
	int& getElem(int index) const;
	int getLength() const;
	void reallocaate(int newLength);
	void resize(int newLength);
	void copyArray();
	void addElemBefore(int elem, int index);
	void delElem(int index);
	int& operator[](int index) const;
};