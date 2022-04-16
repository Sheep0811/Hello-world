#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> use(m, 4);
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; ++i)
    {
        char tmp;
        cin >> tmp;
        bool flag = false;
        if (tmp == 'A')
        {
            for (int j = 0; j < m; ++j)
            {
                if (use[j] >= 1)
                {
                    use[j]--;
                    flag = true;
                    ans1=j+1;
                    ans2=4-use[j];
                    break;
                }
            }
        }
        else
        {
            for (int j = 0; j < m; ++j)
            {
                if (use[j] == 4)
                {
                    use[j]=0;
                    flag = true;
                    ans1=j+1;
                    ans2=1;
                    break;
                }
            }
        }
        if(flag!=true){
            cout<<0<<endl<<0;
            return 0;
        }
    }
    cout<<ans1<<endl<<ans2;

    system("pause");
    return 0;
}
