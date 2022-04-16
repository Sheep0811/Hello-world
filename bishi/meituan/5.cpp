#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n,k1,k2;
    cin>>n>>k1>>k2;
    vector<int>a;
    vector<int>b;
    for(int i=0;i<n;++i)
    {
        int tmp;
        cin>>tmp;
        if(tmp%k1==0)a.push_back(tmp);
        if(tmp%k2)b.push_back(tmp);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    cout<<a[a.size()-1]+b[b.size()-1];

	system("pause");
	return 0;
}

