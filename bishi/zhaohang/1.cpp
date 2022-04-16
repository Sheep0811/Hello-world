#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    string a;
    cin>>a;
    int n=a.size();
    string b=a.substr(0,n/2);
    string c=a.substr(n/2);
    reverse(b.begin(),b.end());
    reverse(c.begin(),c.end());
    cout<<b+c<<endl;
    system("pause"); 
    return 0;
}