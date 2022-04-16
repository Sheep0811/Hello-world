#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                char tmp;
                cin >> tmp;
                if (tmp == '-')
                    a[i][j] = 0;
                else if (tmp == 'b')
                    a[i][j] = 2;
                else if (tmp == 'w')
                    a[i][j] = 1;
            }
        }
        int a = 1, b = 2;
        while (m--)
        {
            int x, y, k = 0;
            cin >> x >> y;
            a[x][y] == a;
            int maxlen=0;
            int tmpx=x;tmpy=y;
            while(tmpy>0)
            {
                tmpy--;
                if(a[x][tmpy]==b)
                {
                    if(abs(tmpy-y)>max)
                    {
                        max=abs(tmpx-x);
                        k=1;
                    }
                }
            }
            tmpx=x;tmpy=y;
            while(tmpx>0 && tmpy>0)
            {
                tmpx--;tmpy--;
                if(a[tmpx][tmpy]==b)
                {
                    if(abs(tmpx-x)>max)
                    {
                        max=abs(tmpx-x);
                        k=2;
                    }
                }
            }tmpx=x;tmpy=y;
            while(tmpy>0)
            {
                tmpy--;
                if(a[x][tmpy]==b)
                {
                    if(abs(tmpy-y)>max)
                    {
                        max=abs(tmpy-y);
                        k=3;
                    }
                }
            }tmpx=x;tmpy=y;
            while(tmpx<n-1&&tmpy>0)
            {
                tmpx++;tmpy--;
                if(a[tmpx][tmpy]==b)
                {
                    if(abs(tmpy-y)>max)
                    {
                        max=abs(tmpy-y);
                        k=4;
                    }
                }
            }tmpx=x;tmpy=y;

            while(tmpy<n-1)
            {
                tmpy++
                if(a[x][tmpy]==b)
                {
                    if(abs(tmpy-y)>max)
                    {
                        max=abs(tmpy-y);
                        k=5;
                    }
                }
            }tmpx=x;tmpy=y;
            while(tmpx<n-1 && tmpy<n-1)
            {
                tmpx++;tmpy++;
                if(a[tmpx][y]==b)
                {
                    if(abs(tmpx-x)>max)
                    {
                        max=abs(tmpx-x);
                        k=6;
                    }
                }
            }tmpx=x;tmpy=y;
            while(tmpx<n-1)
            {
                tmpx++;
                if(a[tmpx][y]==b)
                {
                    if(abs(tmpx-x)>max)
                    {
                        max=abs(tmpx-x);
                        k=7;
                    }
                }
            }tmpx=x;tmpy=y;
            while(tmpx<n-1 && tmpy>0k)
            {
                tmpx++;tmpy--;
                if(a[tmpx][tmpy]==b)
                {
                    if(abs(tmpx-x)>max)
                    {
                        max=abs(tmpx-x);
                        k=8;
                    }
                }
            }tmpx=x;tmpy=y;
            swap(a, b);
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (a[i][j] == 0)
                    cout<< '-';
                else if (a[i][j] == 1)
                    cout<< 'w' 
                else if (a[i][j] == 2)
                    cout<<'b';
            }
            cout<<endl;
        }
    }
    system("pause");
    return 0;
}