#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll ksm(ll a,ll b,ll p);
const int N= 1e7+5;
int pr[N/10],npr;
bool nop[N];
void init(int n);
ll mod=1e9+7;
const int maxn=1e7;
int a[maxn];
int main()
{
    int n;
    cin>>n;
    int lim=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        lim=max(a[i],lim);
    }
    init(lim);
    ll tans=ksm(2,(ll)n,mod);
    ll ans=0;
    for(int i=0;i<npr;++i)
    {
        int ndiv=0;
        for(int j=0;j<n;++j)
        {
            if(a[j]%pr[i]==0)ndiv++;
        }
        if(ndiv>0)
        {
            ans=(ans+tans+mod-ksm(2,(ll)(n-ndiv),mod))%mod;
        }
    }
    cout<<ans;
    system("pause");
    return 0;
}

ll ksm(ll a,ll b,ll p)
{
    ll ret =1;
    while (b)
    {
        if(b&1)ret=(ret*a)%p;
        a=(a*a)%p;
        b>>=1;
    }
    return ret;
}

void init(int n)
{
    npr=0;
    for(int i=2;i<=n;++i)
    {
        if(!nop[i])
        {
            pr[npr++]=i;
        }
        for(int j=0;j<npr && i*pr[j]<=n;j++){
            nop[i*pr[j]]=1;
            if(i%pr[j]==0){
                break;
            }
        }
    }
}