#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool cmp(vector<int> a, vector<int> b);
int main()
{
    int n;
    cin >> n;
    vector<int> a(6, 0);
    vector<int> b(6, 0);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            cin >> a[j];
        }
        for (int j = 0; j < 6; ++j)
        {
            cin >> b[j];
        }
        if(!cmp(a,b))
        {
            cout<<"-1";
        }
        else
        cout<<"1";
    }
    system("pause");
    return 0;
}
bool cmp(vector<int> a, vector<int> b)
{
    for (int i = 0; i < 6; ++i)
    {
        if (b[i] == a[0])
        {
            if (i % 2 == 0)
            {
                if (b[i + 1] != a[1])
                    return false;
            }
            else if (i % 2 == 1)
            {
                if (b[i - 1] != a[1])
                    return false;
            }
        }
        else if (b[i] == a[2])
        {
            if (i % 2 == 0)
            {
                if (b[i + 1] != a[3])
                    return false;
            }
            else if (i % 2 == 1)
            {
                if (b[i - 1] != a[3])
                    return false;
            }
        }
        else if (b[i] == a[4])
        {
            if (i % 2 == 0)
            {
                if (b[i + 1] != a[5])
                    return false;
            }
            else if (i % 2 == 1)
            {
                if (b[i - 1] != a[5])
                    return false;
            }
        }
    }
    return true;
}