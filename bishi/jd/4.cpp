
#include <iostream>
#include <string>
 
using namespace std;
 
class tag
{
public:
       static const int a; // static和const顺序先后不影响
};
 
int main()
{
    tag tag;
    cout << tag.a << endl;
	system("pause");
    return 0;
}

