#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

long long change(char a);
int main()
{
    ll sum = 0, tmp = 0;
    string m;
    cin >> m;
    int n = m.size();
    for (int i = 2; i < n; ++i)
    {
        tmp = change(m[i]);
        while (tmp > 0)
        {
            if ((unsigned)tmp & 1)
                sum++;
            tmp = tmp >> 1;
        }
    }

    printf("%lld", sum);
    system("pause");
    return 0;
}

long long change(char a)
{
    long long tmp = 0;
    if ((a >= '0') && (a <= '9'))
    {
        tmp = a - 48;
    }
    else if ((a >= 'a') && (a <= 'f'))
    {
        tmp = a - 'a' + 10;
    }
    else
    {
        tmp = 0;
    }

    return tmp;
}