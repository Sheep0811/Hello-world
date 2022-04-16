#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
struct student
{
    string name;
    int y;
    int m;
    int e;
}stu[1010];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>stu[i].name>>stu[i].y>>stu[i].m>>stu[i].e;
    }
    sort(stu,stu+n,[](student a,student b){if(a.y==b.y)return a.name<b.name;return a.y>b.y;});
    cout<<stu[0].name<<" ";
    for(int i=1;i<n;++i)
    {
        if(stu[i].y==stu[i-1].y)
        cout<<stu[i].name<<" ";
        else
        break;
    }
    cout<<endl;
    sort(stu,stu+n,[](student a,student b){if(a.m==b.m)return a.name<b.name;return a.m>b.m;});
    cout<<stu[0].name<<" ";
    for(int i=1;i<n;++i)
    {
        if(stu[i].m==stu[i-1].m)
        cout<<stu[i].name<<" ";
        else
        break;
    }
    cout<<endl;
    sort(stu,stu+n,[](student a,student b){if(a.e==b.e)return a.name<b.name;return a.e>b.e;});
    cout<<stu[0].name<<" ";
    for(int i=1;i<n;++i)
    {
        if(stu[i].e==stu[i-1].e)
        cout<<stu[i].name<<" ";
        else
        break;
    }
    cout<<endl;
    system("pause"); 
    return 0;
}