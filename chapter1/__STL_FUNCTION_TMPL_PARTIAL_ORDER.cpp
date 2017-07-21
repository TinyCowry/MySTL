/*
函数模板的特化
clang无法编译
*/

#include <iostream>
using namespace std;

class alloc {};

template<class T, class Alloc = alloc>
class vector
{
public:
	swap(vector<T, Alloc>&) {cout << "swap()" << endl;}
};


int main(int argc, char const *argv[])
{
	vector<int> x, y;
	swap(x, y):
	return 0;
}

#ifdef __STL_FUNCTION_TMPL_PARTIAL_ORDER 
template<class T, class Alloc>
inline void swap(vector<T, Alloc>& x, vector<T, Alloc>& y)
{
	x.swap(y);
}
#endif
