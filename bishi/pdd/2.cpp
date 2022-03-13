#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

string reverse(string a,int n);
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;++i)
    {
        int k,l;
        cin>>k>>l;
        string a;
        cin>>a;
        if(a==reverse(a,l) || k==0)
        {
            cout<<"1"<<endl;
        }
        else
        cout<<"2"<<endl;
    }
    system("pause");
    return 0;
}

string reverse(string a,int n)
{
    string ans;
    for(int i=n-1;i>=0;--i)
    {
        ans+=a[i];
    }
    return ans;
}