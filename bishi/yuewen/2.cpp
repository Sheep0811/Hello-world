#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    string s;
    int n=0;
    cin>>s>>n;
    int k=s.size();
    n=n%k;
    cout<< s.substr(n,k)+s.substr(0,n);
    system("pause"); 

    return 0;
}