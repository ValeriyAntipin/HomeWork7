#include "IntegerArray.h"
using namespace std;
const int SIZE = 20;

int main()
{
	IntegerArray testArray(SIZE);
	for (int i = 0; i < SIZE; ++i)
	{
		testArray[i] = i + 1;
	}
	int elem;
	try
	{
		elem = testArray.getElem(10);
		cout << elem << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	try
	{
		testArray.addElemBefore(100, 2);
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	testArray.resize(10);
	testArray.copyArray();
	testArray.delElem(19);
	int length;
	length = testArray.getLength();
	cout << length << endl;
	return 0;
}