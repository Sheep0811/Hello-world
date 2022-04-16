# 	extern用法

在C语言中，修饰符extern用在变量或者函数的声明前，用来说明“此变量/函数是在**别处定义的，要在此处引用**”。

1. **extern修饰变量的声明**

   **C++文件内声明全局变量** 

​	如果外部变量不在文件的开头定义，其有效的作用范围只限于定义处到文件终了。

​	如果在定义点之前的函数想引用该全局变量，则应该在引用之前用关键字extern，对该变量作外部变量声明，表示该变量是一个将在下		面定义的全局变量。

​	有了声明，就可以合乎规则地引用该全局变量，这种声明称为提前引用声明。

​	**C++多文件程序声明外部变量**

​	如果一个程序包含两个文件，在两个文件中都要用到同一个外部变量，不能分别在两个文件中各自定义一个外部变量。

​	正确的做法是：在任一文件中定义外部变量，而在另一文件中用extern对该变量作外部变量声明。

​	用extern扩展全局变量的作用域，虽然能为C++编码带来方便，但应十分慎重，因为在执行一个文件中的函数时，可能会改变了该全局变量的值，从而会影响到另一文件中的函数执行结果。

2. **extern修饰函数声明**

从本质上来讲，变量和函数没有区别。函数名是指向函数二进制块开头处的指针。

如果文件a.c需要引用b.c中的函数，比如在b.c中原型是int fun(int mu)，那么就可以在a.c中声明extern int fun（int mu），然后就能使用fun来做任何事情。

就像变量的声明一样，extern int fun（int mu）可以放在a.c中任何地方，而不一定非要放在a.c的文件作用域的范围中。

对其他模块中函数的引用，最常用的方法是包含这些函数声明的头文件。使用extern和包含头文件来引用函数有什么区别呢？extern的引用方式比包含头文件要简洁得多！extern的使用方法是直接了当的，想引用哪个函数就用extern声明哪个函数。

这样做的一个明显的好处是，会加速程序的编译（确切的说是预处理）的过程，节省时间。在大型C程序编译过程中，这种差异是非常明显的。

3. **extern修饰符可用于指示C或者C＋＋函数的调用规范**

比如在C＋＋中调用C库函数，就需要在C＋＋程序中用extern “C”声明要引用的函数。

这是给链接器用的，告诉链接器在链接的时候用C函数规范来链接。主要原因是C＋＋和C程序编译完成后在目标代码中命名规则不同。

# static作用

- （1）在修饰变量的时候，static 修饰的静态局部变量只执行初始化一次，而且延长了局部变量的生命周期，直到程序运行结束以后才释放。
- （2）static 修饰全局变量的时候，这个全局变量只能在本文件中访问，不能在其它文件中访问，即便是 extern 外部声明也不可以。
- （3）static 修饰一个函数，则这个函数的只能在本文件中调用，不能被其他文件调用。static 修饰的变量存放在全局数据区的静态变量区，包括全局静态变量和局部静态变量，都在全局数据区分配内存。初始化的时候自动初始化为 0。
- （4）不想被释放的时候，可以使用static修饰。比如修饰函数中存放在栈空间的数组。如果不想让这个数组在函数调用结束释放可以使用 static 修饰。
- （5）考虑到数据安全性（当程序想要使用全局变量的时候应该先考虑使用 static）。

# priority_queue优先队列

```c++
#include <queue> 

priority_queue<int> pq1 *// 大根堆* 

priority_queue<int, vector<int>, greater<int>> pq2 *// 小根堆*
    
struct cmp {bool operator()(int a,int b) {return a > b;}}; // 自定义小根堆
priority_queue<int, vector<int>, cmp> pq;
```

# vector缩容

vector一共有三个指针，一个指向开头，一个指向结尾，另外一个指向容量的边界。

**size 与 capacity区别**

- **size** 表示vector中元素的个数，此方法是返回该vector对象当前有多少个元素。
- **capacity** 表示vector可容纳的元素大小，意思是容量，此方法返回的是该vector对象最多能容纳多少个元素。
- **resize()，设置大小（size）;
  reserve()，设置容量（capacity）;**

这里简单的使用**swap**,清除元素并回收内存

```bash
  vector<T>(v).swap(v);  作用相当于：    
  {   
      std::vector<T>   temp(v);    //1   
      temp.swap(v);                //2   
  }   
```

 第一句产生一个和v内容一模一样的vector，只不过temp的容量是恰好满足其大小的 。
 第二句把v和temp交换 ，然后temp就自动解析掉了  
 这样写的作用是：把v的容量缩小到最佳值，该例中执行这句时，capacity收缩到 10。

# C++模板的偏特化与全特化

## 模板的声明

类模板和函数模板的声明方式是一样的，在类定义/模板定义之前声明模板参数列表。例如：

```c++
// 类模板
template <class T1, class T2>
class A{
    T1 data1;
    T2 data2;
};

// 函数模板
template <class T>
T max(const T lhs, const T rhs){   
    return lhs > rhs ? lhs : rhs;
}
```

## 全特化

通过[全特化](http://en.cppreference.com/w/cpp/language/template_specialization)一个模板，可以对一个特定参数集合自定义当前模板，类模板和函数模板都可以全特化。 全特化的模板参数列表应当是空的，并且应当给出"模板实参"列表：

```c++
// 全特化类模板
template <>
class A<int, double>{
    int data1;
    double data2;
};

// 函数模板
template <>
int max(const int lhs, const int rhs){   
    return lhs > rhs ? lhs : rhs;
}
```

注意类模板的全特化时在类名后给出了"模板实参"，但函数模板的函数名后没有给出"模板实参"。 这是因为编译器根据`int max(const int, const int)`的函数签名可以推导出来它是`T max(const T, const T)`的特化。

## 特化的歧义

上述函数模板不需指定"模板实参"是因为编译器可以通过函数签名来推导，但有时这一过程是有歧义的：

```c++
template <class T>
void f(){ T d; }

template <>
void f(){ int d; }
```

此时编译器不知道`f()`是从`f<T>()`特化来的，编译时会有错误：

```c++
error: no function template matches function template specialization 'f'
```

这时我们便需要显式指定"模板实参"：

```c++
template <class T>
void f(){ T d; }

template <>
void f<int>(){ int d; }
```

## 偏特化

类似于全特化，偏特化也是为了给自定义一个参数集合的模板，但偏特化后的模板需要进一步的实例化才能形成确定的签名。 值得注意的是函数模板不允许偏特化，这一点在[Effective C++: Item 25](https://harttle.land/2015/08/23/effective-cpp-25.html)中有更详细的讨论。 偏特化也是以`template`来声明的，需要给出剩余的"模板形参"和必要的"模板实参"。例如：

```c++
template <class T2>
class A<int, T2>{
    ...
};
```

函数模板是不允许偏特化的，下面的声明会编译错：

```c++
template <class T1, class T2>
void f(){}

template <class T2>
void f<int, T2>(){}
```

但函数允许重载，声明另一个函数模板即可替代偏特化的需要：

```c++
template <class T2>
void f(){}              // 注意：这里没有"模板实参"
```

多数情况下函数模板重载就可以完成函数偏特化的需要，一个例外便是`std`命名空间。 `std`是一个特殊的命名空间，用户可以特化其中的模板，但不允许添加模板（其实任何内容都是禁止添加的）。 因此在`std`中添加重载函数是不允许的，在[Effective C++: Item 25](https://harttle.land/2015/08/23/effective-cpp-25.html)中给出了一个更详细的案例。

# **emplace_back**()和**push_back**()的**区别**

**push_back**() 向容器尾部添加元素时，首先会创建这个元素，然后再将这个元素拷贝或者移动到容器中（如果是拷贝的话，事后会自行销毁先前创建的这个元素）；而**emplace_back**() 在实现时，则是直接在容器尾部创建这个元素，省去了拷贝或移动元素的过程。

# static和const 修饰类的成员变量

**1.static 修饰类的成员变量**

-  1). 静态成员变量是先于类的对象而存在
-  2). 这个类的所有对象共用一个静态成员
-  3). 如果静态成员是公有的，那么可以直接通过类名调用
-  4). 静态成员数据在声明时候类外初始化

```c++
#include <iostream>
using namespace std;
class Data
{
public:
    Data(){}
    ~Data(){}
    void show()
    {
        cout<<this->data<<" "<<number<<endl;
    }
 
    static void showData()//先于类的对象而存在
    {
        //这方法调用的时候不包含this指针
        cout<<" "<<number<<endl;
    }
 
private:
    int data;
public:
    static int number; //静态数据在声明时候类外初始化
};
int Data::number=0;//静态成员初始化
 
int main()
{
    Data::showData();//通过类名直接调用
 
 
    Data::number = 100;//通过类名直接使用
    Data d;
    d.show();
    d.showData();//通过对象调用
 
    cout << "Hello World!" << endl;
    return 0;
}
```

**2.static 修饰类的成员方法**

-  1). 静态成员函数是先于类的对象而存在
-  2). 可用类名直接调用（公有）
-  3). 在静态成员函数中没有this指针，所以不能使用非静态成员

**3.const** 修饰成员变量

```csharp
const int data;
```

const 修饰的成员变量必须在构造方法的参数列表初始化（const static int pdata=10;除外）const 修饰的成员变量不能被修改

**4.const** 修饰成员方法

```csharp
void showData()const{ }
```

const 修饰的成员函数中不能修改成员变量，不能调用非 const 修饰的函数

# 虚函数	

[虚函数析](https://www.cnblogs.com/qg-whz/p/4909359.html)

1、派生类重新实现虚函数。查看其虚函数表和虚函数表中虚函数的地址 

```c++
#include<iostream>  
using namespace std;  
class Base{  
    public:   
    virtual void fun()  
    {  
        cout<<"This is Base Class"<<endl;  
    }  
};  
class Derived:public Base{  
    public:  
    void fun()  
    {  
        cout<<"This is Derived Class"<<endl;  
    }  
};  
int main()  
{  
    Base B;  
    Derived D;   
    int **p=(int**)&B;  
    cout<<"基类的虚函数表地址:"<<p[0]<<endl;  
    cout<<"基类的虚函数表中虚函数的地址:0x"<<hex<<p[0][0]<<endl;  
    p=(int**)&D;  
    cout<<"派生类的虚函数表地址:"<<p[0]<<endl;  
    cout<<"派生类的虚函数表中虚函数的地址:0x"<<hex<<p[0][0]<<endl;  
      

    return 0;  

}  
```

输出结果:
基类的虚函数表地址:0x445060
基类的虚函数表中虚函数的地址:0x415390
派生类的虚函数表地址:0x445070
派生类的虚函数表中虚函数的地址:0x4153dc
可以看出，基类和派生类的虚函数表不同，虚函数的地址也不同。这个结果符合预期，因为派生类中重新实现了虚函数，基类肯定
有自己的虚函数表，虚函数的地址自然是重新实现的那个。


2、派生类不重新实现虚函数。查看其虚函数表和虚函数表中虚函数的地址 

```c++
#include<iostream>  
using namespace std;  
class Base{  
    public:   
    virtual void fun()  
    {  
        cout<<"This is Base Class"<<endl;  
    }  
};  
class Derived:public Base{  
      
};  
int main()  
{  
    Base B;  
    Derived D;   
    int **p=(int**)&B;  
    cout<<"基类的虚函数表地址:"<<p[0]<<endl;  
    cout<<"基类的虚函数表中虚函数的地址:0x"<<hex<<p[0][0]<<endl;  
    p=(int**)&D;  
    cout<<"派生类的虚函数表地址:"<<p[0]<<endl;  
    cout<<"派生类的虚函数表中虚函数的地址:0x"<<hex<<p[0][0]<<endl;  
  
    return 0;  

}  
```

输出结果: 
基类的虚函数表地址:0x445050
基类的虚函数表中虚函数的地址:0x415390
派生类的虚函数表地址:0x445060
派生类的虚函数表中虚函数的地址:0x415390
派生类没有实现虚函数，但是派生类有自己的虚函数表，但是虚函数表中，虚函数的地址和基类中虚函数的地址一样。 

# 友元函数

类的友元函数是定义在类外部，但有权访问类的所有私有（private）成员和保护（protected）成员。尽管友元函数的原型有在类的定义中出现过，但是友元函数并不是成员函数。**普通友元函数不能定义为虚函数**，因为不是成员函数，即使继承也不会继承非成员函数，所以就不存在多态，定义成虚函数就没意义了

**但虚函数可以是另一个类的友元**

因为在一个类里声明友元时 由于友元不是自己的成员函数 自然在自己的类里不能把它声明为虚函数

但是在友元本身可以是虚函数

注意 友元是另外一个类的成员函数(在那个类里 它可以定义为虚函数)

这个类将它声明为自己的友元,只是让它可以存取自己的私有变量

```c++
public class A
{
   private:
        int d;
  public:
    friend B::Geta(A a);
}

public class B
{
  public:
    virtual int Geta(A &a)
   { 
       return a->d;
   }
}
//这里Geta是class B的一个虚成员函数
//同时它也是class A的一个友元函数,所以他能够存取A的私有变量d
```

友元可以是一个函数，该函数被称为友元函数；友元也可以是一个类，该类被称为友元类，在这种情况下，整个类及其所有成员都是友元。

如果要声明函数为一个类的友元，需要在类定义中该函数原型前使用关键字 **friend**，如下所示：

```
class Box
{
   double width;
public:
   double length;
   friend void printWidth( Box box );
   void setWidth( double wid );
};
```

声明类 ClassTwo 的所有成员函数作为类 ClassOne 的友元，需要在类 ClassOne 的定义中放置如下声明：

```
friend class ClassTwo;
```

请看下面的程序：

## 实例

```c++
#include <iostream>

using namespace std;

class Box
{
    double width;
public:
    friend void printWidth(Box box);
    friend class BigBox;
    void setWidth(double wid);
};

class BigBox
{
public :
    void Print(int width, Box &box)
    {
        // BigBox是Box的友元类，它可以直接访问Box类的任何成员
        box.setWidth(width);
        cout << "Width of box : " << box.width << endl;
    }
};

// 成员函数定义
void Box::setWidth(double wid)
{
    width = wid;
}

// 请注意：printWidth() 不是任何类的成员函数
void printWidth(Box box)
{
    /* 因为 printWidth() 是 Box 的友元，它可以直接访问该类的任何成员 */
    cout << "Width of box : " << box.width << endl;
}

// 程序的主函数
int main()
{
    Box box;
    BigBox big;

    // 使用成员函数设置宽度
    box.setWidth(10.0);

    // 使用友元函数输出宽度
    printWidth(box);

    // 使用友元类中的方法设置宽度
    big.Print(20, box);

    getchar();
    return 0;
}
```

当上面的代码被编译和执行时，它会产生下列结果：

```
Width of box : 10
```

# C++中的new、operator new与placement new

**C++中的new/delete与operator new/operator delete**

> new operator/delete operator就是new和delete操作符，而operator new/operator delete是函数。

2. new封装了malloc，直接free不会报错，但只释放内存不会析构对象。

**new分为两步**

1. 内存分配
   　　　　调用相应的operator new( )分配内存
2. 构造函数
   　　　　调用相应的构造函数　
3. .分配空间并构造完成后，返回一个指向该对象的指针　

　实验代码：

```c++
class T{  
public:  
    T(){  
        cout << "构造函数。" << endl;  
    }  

    ~T(){  
        cout << "析构函数。" << endl;  
    }  

    void * operator new(size_t sz){  

        T * t = (T*)malloc(sizeof(T));  //operator new就是简单的分配内存即可
        cout << "内存分配。" << endl;  

        return t;  
    }  

    void operator delete(void *p){  

        free(p);  
        cout << "内存释放。" << endl;  

        return;  
    }  
};  

int main()  
{  
    T * t = new T(); // 先 内存分配 ，再 构造函数  

    delete t; // 先 析构函数， 再 内存释放  

    return 0;  
}  　　　　　　　 
```
**new的内部实现机制**
我们都知道new分为两步完成，但是new是怎样完成这两步的呢？

> 开始我以为是在new内部封装了一个两个函数，一个用来分配内存，另一个用来调用相应的构造函数。

​	但事实上并非如此，根本就没有一个“隐藏”的new函数，**编译器会自动将new改写成一个内存分配函数，一个构造函数。**
这里其实还有一个更本质的问题需要说明：**new的本质是关键字**，编译器在背后的操作可能与我们的想象大不相同。**能够重载的是函数，是运算符，关键字是不能重载的**（有的博客中说operator new可以重载，new不能重载就是这个原因，更本质的原因可以概括为不能重载关键字），这也是为什么运算符重载前面必须要有operator的原因。+(int a)，new(int a)都是错的。
简而言之，new在编译器的操作下会变成两部分代码，一部分分配内存，一部分调用构造函数。

这其实是可以做实验验证的：
	就在上述代码中加入new T并打上断点，再F10一步一步地调试，发现先进入类中的operator new，执行完后并没有到new T的下一行，而是依然停留在new这一行，继续F10进入构造函数。就是说new T这一行代码停留了两次。这意味着编译器确实将new T这一行代码翻译成了两次函数调用。

第二种验证方式就是直接使用反汇编查看代码（推荐）：
　　　　　　![反汇编](https://img-blog.csdn.net/20180802100715188?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NvbmdjaHV3YW5nMTg2OA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)
　　可以看到的确有两个call，第一个call T::operator new( )。第二个call T::T( )。注意：真正的汇编中没有具体的函数名，只有相应的地址。显示函数名是VS的一个比较便利的功能。

**::new与new**
　　在全局命名空间中有一个自带的、隐藏的operator new专门用来分配内存。默认情况下编译器会将new这个关键字翻译成这个operator new和相应的构造函数。

　　但在有的情况下，用户自己会在类中重载operator new，这种情况下，编译器默认会使用类中重载的operator new（本质上因为编译器会从命名空间由内而外查找自己想要的函数，选用第一个）。

　　如果我们想要继续使用默认的operator new，就应该写成::new 字面意思就是调用最外层命名空间中的operator new

　值得一提的是最外层的（也是默认的）operator new也是可以被重载的。通过这种方式我们可以改变所有new的部分行为。

## **placement new**
new分为两步走，先分配内存，后调用构造函数。我们自然而然可以想到，可不可以保持一块内存，反复构造析构，这样可以省略中间的多次分配内存。**由于malloc内存会导致系统调用**，这可以节省大量的系统开销。C++标准也是这么想的，所以他们提供了placement new。

placement new 是重载operator new 的一个标准、全局的版本，**它不能够被自定义的版本代替**（不像普通版本的operator new和operator delete能够被替换）。它并不分配内存，只是返回指向已经分配好的某段内存的一个指针。因此不能删除它，但需要调用对象的析构函数。

如果你想在已经分配的内存中创建一个对象，使用new时行不通的。**也就是说placement new允许你在一个已经分配好的内存中（栈或者堆中）构造一个新的对象。**原型中void* p实际上就是指向一个已经分配好的内存缓冲区的的首地址。

```c++
void *operator new( size_t, void * p ) throw() { return p; }
```

placement new的执行忽略了size_t参数，只返还第二个参数。其结果是允许用户把一个对象放到一个特定的地方，达到调用构造函数的效果。和其他普通的new不同的是，它在括号里多了另外一个参数。比如：

```c++
Widget * p = new Widget;          //ordinary new
pi = new (ptr) int; pi = new (ptr) int;   //placement new
```

括号里的参数ptr是一个指针，它指向一个内存缓冲器，placement new将在这个缓冲器上分配一个对象。Placement new的返回值是这个被构造对象的地址(比如括号中的传递参数)。placement new主要适用于：在对时间要求非常高的应用程序中，因为这些程序分配的时间是确定的；长时间运行而不被打断的程序；以及执行一个垃圾收集器 (garbage collector)。

使用示例：

```c++
char* ptr = new char[sizeof(T)]; // allocate memory  
T* tptr = new(ptr) T;            // construct in allocated storage ("place")  
tptr->~T();                      // destruct  
delete[] ptr;                    // deallocate memory  
```

**Placement new 存在的理由**

1. 用placement new 解决buffer的问题

问题描述：用new分配的数组缓冲时，由于调用了默认构造函数，因此执行效率上不佳。若没有默认构造函数则会发生编译时错误。如果你想在预分配的内存上创建对象，用缺省的new操作符是行不通的。要解决这个问题，你可以用placement new构造。它允许你构造一个新对象到预分配的内存上。

2. 增大时空效率的问题

**使用new操作符分配内存需要在堆中查找足够大的剩余空间**，显然这个操作速度是很慢的，而且有可能出现无法分配内存的异常（空间不够）。placement new就可以解决这个问题。我们构造对象都是在一个预先准备好了的内存缓冲区中进行，不需要查找内存，内存分配的时间是常数；而且不会出现在程序运行中途出现内存不足的异常。所以，**placement new非常适合那些对时间要求比较高，长时间运行不希望被打断的应用程序。**

**Placement new使用步骤**

在很多情况下，placement new的使用方法和其他普通的new有所不同。这里提供了它的使用步骤。

**第一步 缓存提前分配**

有三种方式：

为了保证通过placement new使用的缓存区的memory alignment(内存队列)正确准备，使用普通的new来分配它：

1. 在堆上进行分配

```c++
class Task ;
char * buff = new [sizeof(Task)]; //分配内存
```

(请注意auto或者static内存并非都正确地为每一个对象类型排列，所以，你将不能以placement new使用它们。)

2. 在栈上进行分配

```C++
class Task ;
char buf[N*sizeof(Task)]; //分配内存
```

3. 还有一种方式，就是直接通过地址来使用。(必须是有意义的地址)

```c++
void* buf = reinterpret_cast<void*> (0xF00F)
```

**第二步：对象的分配**

在刚才已分配的缓存区调用placement new来构造一个对象。

```c++
Task *ptask = new (buf) Task
```

**第三步：使用**

按照普通方式使用分配的对象：

```c++
ptask->memberfunction();

ptask-> member;

//...
```

**第四步：对象的析构**

一旦你使用完这个对象，你必须调用它的析构函数来毁灭它。按照下面的方式调用析构函数：

```c++
ptask->~Task(); //调用外在的析构函数
```

**第五步：释放**

你可以反复利用缓存并给它分配一个新的对象（重复步骤2，3，4）如果你不打算再次使用这个缓存，你可以象这样释放它：

```c++
delete [] buf;
```

跳过任何步骤就可能导致运行时间的崩溃，内存泄露，以及其它的意想不到的情况。如果你确实需要使用placement new，请认真遵循以上的步骤。

# 限制对象只能建立在堆上或者栈上

1. **只能建立在堆上**

​    类对象只能建立在堆上，就是不能静态建立类对象，即不能直接调用类的构造函数。

​    容易想到将构造函数设为私有。在构造函数私有之后，无法在类外部调用构造函数来构造类对象，只能使用new运算符来建立对象。然而，前面已经说过，new运算符的执行过程分为两步，C++提供new运算符的重载，其实是只允许重载operator new()函数，而operator()函数用于分配内存，无法提供构造功能。因此，这种方法不可以。

​    当对象建立在栈上面时，是由编译器分配内存空间的，调用构造函数来构造栈对象。当对象使用完后，编译器会调用析构函数来释放栈对象所占的空间。编译器管理了对象的整个生命周期。如果编译器无法调用类的析构函数，情况会是怎样的呢？比如，类的析构函数是私有的，编译器无法调用析构函数来释放内存。所以，**编译器在为类对象分配栈空间时，会先检查类的析构函数的访问性**，其实不光是析构函数，只要是非静态的函数，编译器都会进行检查。**如果类的析构函数是私有的，则编译器不会在栈空间上为类对象分配内存。**

​    因此，**将析构函数设为私有**，类对象就无法建立在栈上了。代码如下：

```c++
class A
{
public:
    A(){}
    void destory(){delete this;}
private:
    ~A(){}
};
```

​        试着使用A a;来建立对象，编译报错，提示析构函数无法访问。这样就只能使用new操作符来建立对象，构造函数是公有的，可以直接调用。**类中必须提供一个destory函数，来进行内存空间的释放。类对象使用完成后，必须调用destory函数。**
​        上述方法的一个缺点就是，无法解决继承问题。如果A作为其它类的基类，则析构函数通常要设为virtual，然后在子类重写，以实现多态。因此析构函数不能设为private。还好C++提供了第三种访问控制，protected。将析构函数设为protected可以有效解决这个问题，类外无法访问protected成员，子类则可以访问。

​    另一个问题是，类的使用很不方便，使用new建立对象，却使用destory函数释放对象，而不是使用delete。（**使用delete会报错，因为delete对象的指针，会调用对象的析构函数，而析构函数类外不可访问**）这种使用方式比较怪异。为了统一，可以将构造函数设为protected，然后提供一个public的static函数来完成构造，这样不使用new，而是使用一个函数来构造，使用一个函数来析构。代码如下，类似于单例模式：

```c++
class A
{
protected:
    A(){}
    ~A(){}
public:
    static A* create()
    {
        return new A();
    }
    void destory()
    {
        delete this;
    }
};
```


这样，调用create()函数在堆上创建类A对象，调用destory()函数释放内存。


**2、只能建立在栈上**

只有使用new运算符，对象才会建立在堆上，因此，**只要禁用new运算符就可以实现类对象只能建立在栈上**。将operator new()设为私有即可。代码如下：

```C++
class A
{
private:
    void* operator new(size_t t){}     // 注意函数的第一个参数和返回值都是固定的
    void operator delete(void* ptr){} // 重载了new就需要重载delete
public:
    A(){}
    ~A(){}
};
```

# memcpy和memmove的区别
都是C语言中的库函数，在头文件string.h中，作用是拷贝一定长度的内存的内容，原型分别如下：

```c
void *memcpy(void* dst, const void *src, size_t count);

void *memmove(void* dst, const void *src, size_t count);
```

他们的作用是一样的，唯一的区别是，当内存发生局部重叠的时候，memmove保证拷贝的结果是正确的，memcpy不保证拷贝的结果的正确。

![img](https://segmentfault.com/img/bVcTq3w)

第一种情况下，拷贝重叠的区域不会出现问题，内容均可以正确的被拷贝。
第二种情况下，问题出现在右边的两个字节，这两个字节的原来的内容首先就被覆盖了，而且没有保存。所以接下来拷贝的时候，拷贝的是已经被覆盖的内容，显然这是有问题的。
实际上，memcpy只是memmove的一个子集。

二者的c语言实现很简单，有兴趣的朋友可以去看看。在实际情况下，这两个函数都是用汇编实现的。

memmove在copy两个有重叠区域的内存时可以保证copy的正确，而memcopy就不行了，但memcopy比memmove的速度要快一些，如：

```c
char s[] = "1234567890";
char* p1 = s;
char* p2 = s+2;
```

memcpy(p2, p1, 5)与memmove(p2, p1, 5)的结果就可能是不同的，memmove()可以将p1的头5个字符"12345"正确拷贝至p2，而memcpy()的结果就不一定正确了

**变量的命名**

我们在写程序时，一般讲究见到变量的命名，就能让别人基本知道该变量的含义。memcpy内存拷贝，没有问题;memmove，内存移动？错，如果这样理解的话，那么这篇文章你就必须要好好看看了，memmove还是内存拷贝。那么既然memcpy和memmove二者都是内存拷贝，那二者究竟有什么区别呢？

memcpy：

```c
void  *memcpy(void *dest, const void *src, size_t count)
{
assert(dest != NULL || src != NULL);
//assert是一个调试程序时经常使用的宏，在程序运行时它计算括号内的表达式，如果表达式为FALSE (0), 程序将报告错误，并终止执行。 如果表达式不为0，则继续执行后面的语句。 
char *tmp = (char *)dest;
char *p = (char *)src;

while (count--)
{
*tmp++ = *p++;
}
return dest;
}
```

memcpy的实现很简单，一般在笔试时，出现写源码的题目，无非就是需要注意以下几点：

1.确定函数原型;
2.判断参数合法性;
3.逻辑实现（考虑各种情况，统称逻辑实现）;
4.错误处理。

当然了，我的这个没有错误处理，也不需要错误处理。上面，我写出了memcpy的实现源码，实现原理如下图所示：

![img](https://segmentfault.com/img/bVcTq3I)

这样下去，上面的代码会运行的很好，如果出现下面的情况呢？

![img](https://segmentfault.com/img/bVcTq3J)

i、n、k的内存和J、e、l的内存地址重合了，现在再使用上面的代码进行copy时，会出现什么问题呢？你有没有想过这个问题。如果没有，那就现在想想，不急着阅读下面的内容。

然后，我再留一个问题，上面的代码中，为什么都需要将void *转换成char* 呢？比如：
`char *tmp = (char *)dest;`

再说memmove

memmove也是用来实现内存的直接拷贝的。说起这个命名，我个人觉的多少还是有点坑的。既然memmove也是用来内存数据移动的，那就先来看看memmove的实现源码。

```c
void *memmove(void *dest, const void *src, size_t count)
{
assert(dest != NULL || src != NULL)

if (dest < src)
{
	char *p = (char *)dest;
	char *q = (char *)src;
	while (count--)
	{
		*p++ = *q++;
	}
}
else
{
	char *p = (char *)dest + count;
	char *q = (char *)src + count;
	while (count--)
	{
		*--p = *--q;
	}
}
return dest;
}
```

从源码看，memmove的确比memcpy复杂一些;再仔细一看，多了些什么？哦，多了一个else分支，而正是这个else分支，就处理了当src和dest的内存重合的问题。

memcpy和memmove的比较

从实现源码中的确能看出一些猫腻，当出现了src和dest的内存有重合的时机时，memmove的处理规则是**从后往前进行copy**。当然了，重合的问题，需要考虑的以下两种场合。
![img](https://segmentfault.com/img/bVcTq3M)

如图所示，当出现(1)对应的情况时，就需要先从src的头部开始复制;也就是memmove源码中的if分支，这部分源码和memcpy的实现是一致的;当出现(2)对应的情况时，就需要先从src的尾部开始复制，防止出现了覆盖现象。这就是memmove比memcpy多的一个考虑点，所以说，在实际使用时，使用memmove是比memcpy更安全的。

# 在类的成员函数中调用delete this

*在类的成员函数中能不能调用**delete this**？答案是肯定的，能调用，而且很多老一点的库都有这种代码。假设这个成员函数名字叫**release**，而**delete this**就在这个**release**方法中被调用，那么这个对象在调用**release**方法后，还能进行其他操作，如调用该对象的其他方法么？答案仍然是肯定的，调用release之后还能调用其他的方法，但是有个前提：被调用的方法不涉及这个对象的数据成员和虚函数。说到这里，相信大家都能明白为什么会这样 了。*

**根本原因**在于delete操作符的功能和类对象的内存模型。当一个类对象声明时，系统会为其分配内存空间。**在类对象的内存空间中，只有数据成员和虚函数表指针，并不包含代码内容，类的成员函数**单独**放在代码段中**。在调用[成员函数](https://so.csdn.net/so/search?q=成员函数&spm=1001.2101.3001.7020)时，隐含传递一个this指针，让成员函数知道当前是哪个对象在调用它。当调用delete this时，类对象的内存空间被释放。**在deletethis之后进行的其他任何函数调用，只要不涉及到this指针的内容，都能够正常运行**。一旦涉及到this指针，如操作数据成员，调用虚函数等，就会出现**不可预期**的问题。

为什么是不可预期的问题？**delete this之后不是释放了类对象的内存空间了么**，那么这段内存应该已经还给系统，不再属于这个进程。照这个逻辑来看，应该发生**指针错误**，**无访问权限之类的令系统崩溃**的问题才对啊？这个问题牵涉到操作系统的内存管理策略。**deletethis释放了类对象的内存空间，但是内存空间却并不是马上被回收到系统中，可能是缓冲或者其他什么原因，导致这段内存空间暂时并没有被系统收回**。此时这段内存是可以访问的，你可以加上100，加上200，但是其中的值却是不确定的。当你获取数据成员，可能得到的是一串很长的未初始化的随机数；访问虚函数表，指针无效的可能性非常高，造成系统崩溃。

大致明白在成员函数中调用deletethis会发生什么之后，再来看看另一个问题，如果在类的析构函数中调用deletethis，会发生什么？实验告诉我们，会导致堆栈溢出。原因很简单，delete的本质是“为将被释放的内存调用一个或多个析构函数，然后，释放内存”(来自effective c++)。显然，**deletethis会去调用本对象的析构函数，而析构函数中又调用delete this，形成无限递归，造成堆栈溢出，系统崩溃**。

--------------------我是分界面--------------------

上面是某大牛的分析，而在实际的运行过程中使用delelethis确实会直接出现错误。这是因为：在成员函数中调用delete this，首先会调用类的析构函数，this指针已删除，会出现指针错误。

下面是在XCode中使用delete this出现的错误：

```
malloc: *** error forobject 0xbffffa18: pointer being freed was not allocated
```

//注意0xbffffa18即为this的地址

```
*** set a breakpointin malloc_error_break to debug
```

而在VS2010中使用deletethis是直接导致 Debug Assertion Failed！

具体的描述是：**invalid null pointer**

**总结**：**在成员函数中调用deletethis，会导致指针错误，而在析构函数中调用delete this，出导致死循环，造成堆栈溢出。**

PS：this是类中成员函数具有的一个附加的隐含形参，即指向该类对象的一个指针，它与调用成员函数的对象绑定在一起。同时

1. 在普通的非const成员函数中：this的类型是一个指向类类型的const指针，可以改变this指向的值，但是不能改变this所保存的地址**；**

2. 在const成员函数中，this的类型是一个指向const类类型对象的const指针，既不能改变this所指向的对象，也不能改变this所保存的地址。

综上一个对象请求自杀(`delete` `this`).是可以的。但：

1. 必须100%的确定，`this`对象是用 `new`分配的不是用`new[]`，也不是用[定位放置 `new` ，也不是一个栈上的局部对象，也不是全局的，也不是另一个对象的成员，而是明白的普通的`new`）。
2. 必须100%的确定，该成员函数是`this`对象最后调用的的成员函数。
3. 必须100%的确定，剩下的成员函数（`delete` `this`之后的）不接触到 `this`对象任何一块（包括调用任何其他成员函数或访问任何数据成员）。
4. 必须 100%的确定，在`delete` `this`之后不再去访问`this`指针。换句话说，你不能去检查它，将它和其他指针比较，和 `NULL`比较，打印它，转换它，对它做任何事。

# C++ 在类中包含另一个类

除了继承关系外，另一种常用的关系是包含关系，一个类中包含了另一个类实例化的对象作为数据成员，即在类中含有类类型的数据成员。有两种包含类的方法：

方法一： 将数据成员定义成类的指针；

方法二： 直接将数据成员定义成类的实例。

```c++
class Subtarget{ 
    Subtarget(int Parameter1, int Parameter2){};
}  //定义一个类Subtarget，在其他类中可以像使用内置类型一样将该类的对象作为成员对象  

class Target{
    

    std::shared_ptr<Subtarget> subtarget_=nullptr; //方法一 （优选）
    Subtarget subtarget{4,8}；//方法二 （直观方法）

}
```

方法二比较直观，像使用内置类型一样直接实例化Subtarget类型。成员对象必须被初始化，内置类型初始化往往不需要输入参数，比较简洁，但自定义的类的构造函数往往需要输入参数，在构造函数初始值列表中输入大量参数并不方便。相比而言，方法一将类定义成类的指针（使用shared_ptr是为了更安全，防止使用指针时可能产生的内存泄漏），在类的声明中可以先初始化为nullptr，这样将数据成员定义成类的指针实现将类型的初始化推迟到函数定义中：

```
subtarget_.reset(new Subtarget(4,8));
```

将数据成员定义成类的指针更重要的好处是使用 多态 机制。在定义中也可以将subtarget_绑定到Subtarget的派生类中，从而实现多态。

# delete [] 时如何知道数组长度

```
string *psa = new string[10];      //array of 10 empty strings
int *pia = new int[10];           //array of 10 uninitialized ints
```

上面在申请一个数组时都用到了 `new []` 这个表达式来完成，按照我们上面讲到的 new 和 delete 知识，第一个数组是 string 类型，分配了保存对象的内存空间之后，将调用 string 类型的默认构造函数依次初始化数组中每个元素；第二个是申请具有内置类型的数组，分配了存储 10 个 int 对象的内存空间，但并没有初始化。**内置类型一般不会调用构造函数和析构函数**

如果我们想释放空间了，可以用下面两条语句：

```
delete [] psa;
delete [] pia;
```

**如何知道psa数组指向对象的数组的大小？怎么知道调用几次析构函数？**

这个问题直接导致我们需要在 new [] 一个对象数组时，需要保存数组的维度，C++ 的做法是在分配数组空间时多分配了 4 个字节的大小，专门保存数组的大小，在 delete [] 时就可以取出这个保存的数，就知道了需要调用析构函数多少次了。

还是用图来说明比较清楚，我们定义了一个类 A，但不具体描述类的内容，这个类中有显示的构造函数、析构函数等。那么 当我们调用

```
class A *pAa = new A[3];
```

时需要做的事情如下：

<img src="C:\Users\23173\AppData\Roaming\Typora\typora-user-images\image-20220407232940264.png" alt="image-20220407232940264" style="zoom: 80%;" />

从这个图中我们可以看到申请时在数组对象的上面还多分配了 4 个字节用来保存数组的大小，但是最终返回的是对象数组的指针，而不是所有分配空间的起始地址。

这样的话，释放就很简单了：

```
delete []pAa;
```

这里要注意的两点是：

- **调用析构函数的次数是从数组对象指针前面的 4 个字节中取出；**
- **传入 `operator delete[]` 函数的参数不是数组对象的指针 pAa，而是 pAa 的值减 4。**
- 上述图片中红颜色的数字3即存储在四个字节中的数组长度。

## 为什么 new/delete 、new []/delete[] 要配对使用？

```
int *pia = new int[10];
delete []pia;
```

这肯定是没问题的，但如果把 `delete []pia;` 换成 `delete pia;` 的话，会出问题吗？

在 `new []` 时多分配 4 个字节的缘由，因为析构时需要知道数组的大小，但如果不调用析构函数呢（如内置类型，这里的 int 数组）？我们在 `new []` 时就没必要多分配那 4 个字节， delete [] 时直接到第二步释放为 int 数组分配的空间。如果这里使用 `delete pia;`那么将会调用 `operator delete` 函数，传入的参数是分配给数组的起始地址，所做的事情就是释放掉这块内存空间。不存在问题的。

**这里说的使用 `new []` 用 delete 来释放对象的提前是：对象的类型是内置类型或者是无自定义的析构函数的类类型！**

我们看看如果是带有自定义析构函数的类类型，用 `new []` 来创建类对象数组，而用 delete 来释放会发生什么？用上面的例子来说明：

```
class A *pAa = new class A[3];
delete pAa;
```

那么 `delete pAa;` 做了两件事：

- **调用一次 pAa 指向的对象的析构函数；**
- **调用 `operator delete(pAa);` 释放内存。**

显然，这里只对数组的第一个类对象调用了析构函数，后面的两个对象均没调用析构函数，如果类对象中申请了大量的内存需要在析构函数中释放，而你却**在销毁数组对象时少调用了析构函数，这会造成内存泄漏。**

上面的问题你如果说没关系的话，那么第二点就是致命的了！直接释放 pAa 指向的内存空间，这个总是会造成严重的段错误，程序必然会奔溃！因为分配的空间的起始地址是 pAa 指向的地方减去 4 个字节的地方。你应该传入参数设为那个地址！

同理，你可以分析如果使用 new 来分配，用 `delete []` 来释放会出现什么问题？是不是总会导致程序错误？

总的来说，记住一点即可：**new/delete、new[]/delete[] 要配套使用总是没错的！**

# c++中semaphore在Linux下使用

**1、sem_init函数**

sem_init函数是Posix信号量操作中的函数。sem_init() 初始化一个定位在 sem 的匿名信号量。**value 参数指定信号量的初始值。** pshared 参数指明信号量是由进程内线程共享，还是由进程之间共享。**如果 pshared 的值为 0，那么信号量将被进程内的线程共享，**并且应该放置在这个进程的所有线程都可见的地址上(如全局变量，或者堆上动态分配的变量)。

**如果 pshared 是非零值，那么信号量将在进程之间共享**，并且应该定位共享内存区域(见 shm_open(3)、mmap(2) 和 shmget(2))。因为通过 fork(2) 创建的孩子继承其父亲的内存映射，因此它也可以见到这个信号量。所有可以访问共享内存区域的进程都可以用 sem_post(3)、sem_wait(3) 等等操作信号量。初始化一个已经初始的信号量其结果未定义。

```cpp
#include <semaphore.h>
// 初始化
int sem_init(sem_t *sem,int pshared,unsigned int value); 
```

返回值 ：
 sem_init() 成功时返回 0；错误时，返回 -1，并把 errno 设置为合适的值。

**2、semaphore相关函数**

```cpp
// 销毁
int sem_destroy(sem_t *sem); 
// 
int sem_wait(sem_t *sem);  // 资源减少1
int sem_trywait(sem_t *sem);  
int sem_post(sem_t *sem);  // 资源增加1
int sem_getvalue(sem_t *sem); 
```
