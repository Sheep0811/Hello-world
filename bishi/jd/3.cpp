#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class T
{
public:
	T()
	{
		cout << "构造函数。" << endl;
	}

	~T()
	{
		cout << "析构函数。" << endl;
	}

	void *operator new(size_t sz)
	{

		T *t = (T *)malloc(sizeof(T)); // operator new就是简单的分配内存即可
		cout << "内存分配。" << endl;

		return t;
	}

	void operator delete(void *p)
	{

		free(p);
		cout << "内存释放。" << endl;

		return;
	}
};

int main()
{
	T *t =::new T(); // 先 内存分配 ，再 构造函数

	delete t; // 先 析构函数， 再 内存释放
	system("pause");
	return 0;
}