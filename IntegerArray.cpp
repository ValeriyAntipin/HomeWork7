#include "IntegerArray.h"

IntegerArray::IntegerArray(int lenght) : _length(lenght) {
	if (lenght <= 0)
	{
		throw bad_length();
	}
	_data = new int[lenght];
	cout << "Construct!" << endl;
}
IntegerArray::~IntegerArray(){
	_data = nullptr;
	_length = 0;
	delete[] _data;
	cout << "Destruct!" << endl;
}
void IntegerArray::erase(){
	//delete[] _data;
	_data = nullptr;
	_length = 0;
}
int& IntegerArray::getElem(int index) const {
	if (index < 0 || index > _length)
	{
		throw bad_range();
	}
	return _data[index];
}
int IntegerArray::getLength() const {
	return _length;
}
//изменяем размер массива, но удаляются старые данные
void IntegerArray::reallocaate(int newLength) {
	//удаляем данные
	erase();
	if (newLength <= 0)
		return;
	//создаем новый массив
	_data = new int[newLength];
	_length = newLength;
}
//изменяем размер массива, старые данные сохраняются
void IntegerArray::resize(int newLength) {
	if (newLength == _length)	
		return;
	if (newLength <= 0)
	{
		erase();
		return;
	}
	//сначала мы создадим новый массив, чтобы скопировать туда старые данные
	int* data = new int[newLength];

	if (_length > 0)
	{
		int elementsToCopy{ (newLength > _length) ? _length : newLength };
		std::copy_n(_data, elementsToCopy, data);
	}

	delete[] _data;
	_data = data;
	_length = newLength;
}
void IntegerArray::copyArray() {
	int* data = new int[_length];
	std::copy_n(_data, _length, data);
	delete[] _data;
	_data = data;
}
void IntegerArray::addElemBefore(int elem, int index) {
	if (index > _length || index < 0)
	{
		throw bad_range();
	}
	int* data = new int[_length + 1];
	copy_n(_data, index, data);
	data[index] = elem;
	copy_n(_data + index, _length - index, data + index + 1);
	delete[] _data;
	_data = data;
	++_length;
}
void IntegerArray::delElem(int index) {
	if (_length == 1)
	{
		erase();
		return;
	}
	for (int i = index; i < _length; ++i)
	{
		_data[i] = _data[i + 1];
	}
	--_length;
}

int& IntegerArray::operator[](int index)  const{
	return _data[index];
}