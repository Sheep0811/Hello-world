#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef void(*Fun)(void);
class Base
{
public:
	Base(int i) : baseI(i){};

	int getI() { return baseI; }

	static void countI(){};

	virtual ~Base() {}

	virtual void print(void) { cout << "Base::print()"; }

private:
	int baseI;
	static int baseS;
};
class Derive : public Base
{
public:
	Derive(int d) : Base(1000), DeriveI(d){};
	// overwrite父类虚函数
	virtual void print(void) { cout << "Drive::Drive_print()"; }
	// Derive声明的新的虚函数
	virtual void Drive_print() { cout << "Drive::Drive_print()"; }
	virtual ~Derive() {}

private:
	int DeriveI;
};
int main()
{
	Derive d(2000);
    //[0]
    cout << "[0]Base::vptr";
    cout << "\t地址：" << (int *)(&d) << endl;
        //vprt[0]
        cout << "  [0]";
        Fun fun1 = (Fun)*((int *)*((int *)(&d)));
        fun1();
        cout << "\t地址:\t" << *((int *)*((int *)(&d))) << endl;
 
        //vprt[1]析构函数无法通过地址调用，故手动输出
        cout << "  [1]" << "Derive::~Derive" << endl;
 
        //vprt[2]
        cout << "  [2]";
        Fun fun2 = (Fun)*((int *)*((int *)(&d)) + 2);
        fun2();
        cout << "\t地址:\t" << *((int *)*((int *)(&d)) + 2) << endl;
    //[1]
    cout << "[2]Base::baseI=" << *(int*)((int *)(&d) + 1);
    cout << "\t地址：" << (int *)(&d) + 1;
    cout << endl;
    //[2]
    cout << "[2]Derive::DeriveI=" << *(int*)((int *)(&d) + 2);
    cout << "\t地址：" << (int *)(&d) + 2;
    cout << endl;
	system("pause");
	return 0;
}
