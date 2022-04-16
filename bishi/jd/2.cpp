#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<char> tmp(3 * n);
        vector<int> a, b, c;
        int an = 0, bn = 0, cn = 0, k = 1;
        cin >> tmp[0];
        for (int i = 1; i < 3 * n; ++i)
        {
            cin >> tmp[i];
            if (tmp[i] == tmp[i - 1])
                k++;
            else
            {
                if (tmp[i - 1] == 'A')
                {
                    an += k;
                    a.push_back(k);
                }
                else if (tmp[i - 1] == 'B')
                {
                    b.push_back(k);
                    bn += k;
                }
                else
                {
                    cn += k;
                    c.push_back(k);
                }
                k = 1;
            }
        }
        if (tmp[3*n - 1] == 'A')
        {
            an += k;
            a.push_back(k);
        }
        else if (tmp[3*n- 1] == 'B')
        {
            b.push_back(k);
            bn += k;
        }
        else
        {
            cn += k;
            c.push_back(k);
        }
        if(an==bn&&bn==cn)cout<<0<<endl;
    }
}
system("pause");
return 0;
}
