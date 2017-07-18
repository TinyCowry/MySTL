/*
类模板的静态成员Bug
*/
#include <iostream>
using namespace std;

 template < typename T>
class testCase{
public:
	static int _data;
};

//直接初始化
testCase<int>::_data = 1;
testCase<char>::_data = 2;

int main(int argc, char const *argv[])
{
	cout << testCase<int>::_data << endl;
	cout << testCase<char>::_data << endl;

	testCase<int> obj1;
	testCase<char> obj2;
	cout << obj1._data << endl;
	cout << obj2._data << endl;

	//改变静态变量
	obj1._data = 3;
	obj2._data = 4;
	cout << obj1._data << endl;
	cout << obj2._data << endl;

	return 0;
}