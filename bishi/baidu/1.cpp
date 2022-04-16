#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<vector<int>> a (n,vector<int>(n));
    vector<vector<int>> b (n*k,vector<int>(n*k));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            int tmp;
            cin>>tmp;
            for(int p=0;p<k;++p)
            {
                for(int q=0;q<k;++q)
                {
                    b[i*k+p][j*k+q]=tmp;
                }
            }
        }
    }
    for(auto &i:b)
    {
        for(auto &j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
    system("pause");
    return 0;
}