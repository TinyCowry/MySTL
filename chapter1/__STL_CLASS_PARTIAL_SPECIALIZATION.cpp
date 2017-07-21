/*
模板的特化
*/

#include <iostream>
using namespace std;

template<class T, class O>
class TestClass
{
public:
TestClass() 
{
	cout << "class T, class O" << endl;
}
};

template <class T>
class TestClass<T*, T>
{
public:
TestClass()
{
	cout << "class T*, T" << endl;
}	
};

template<class T>
class TestClass<const T*, T>
{
public:
TestClass()
{
	cout << "const T*, T" << endl;
}
};

int main(int argc, char const *argv[])
{
	TestClass<int, char> obj1;
	TestClass<int*, int> obj2;
	TestClass<const int*, int> obj3;
	return 0;
}


