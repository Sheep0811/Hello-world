#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    string s, a, b;
    getline(cin,s);
    int n = s.size()-1;
    for (int i = n; n > 0; i--)
    {
        for (int j = 0; j < int(s.size() - i); ++j)
        {
            a = s.substr(j, i);
            b = s.substr(j+1);
            if (b.find(a) != string::npos)
            {
                cout << a << endl;
                system("pause");
                return 0;
            }
        }
    }
    system("pause");
    return 0;
}