#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <class a, class b>
int test(a x, b t)
{
	cout << "泛型模板" << endl;
	return 1;
}

template <>
int test<int, int>(int x, int t)
{
	cout << "特化泛型模板" << endl;
	return 2;
}

int main()
{
	double a, b;
	int c, d;
	test(a, b);
	test(c, d);
	test(a, c);
	system("pause");
	return 0;
}
