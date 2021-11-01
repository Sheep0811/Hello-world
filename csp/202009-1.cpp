#include<bits/stdc++.h>
using namespace std;
struct ode
{
    int x,y,ans,num;
};
vector<ode>p;
bool cmp(ode a,ode b)
{
    if(a.ans==b.ans)return a.num<b.num;
    return a.ans<b.ans;
}
int main()
{
   ode k;
   int n,a,b;
   cin>>n>>a>>b;
   for(int i=0;i<n;i++){
       k.num=i;
       cin>>k.x>>k.y;
       k.ans=(a-k.x)*(a-k.x)+(b-k.y)*(b-k.y);
       p.push_back(k);
   } 
   sort(p.begin(),p.end(),cmp);
   for(int i=0;i<=2;i++)
   {
       printf("%d\n",p[i].num+1);
   }
   system("pause");
   return 0;
}