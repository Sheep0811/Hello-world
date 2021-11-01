#include<bits/stdc++.h>
using namespace std;
struct student
{
    int num;
    int yu;
    int shu;
    int ying;
    int grade;
};
student stu[310];

bool cmp(student a,student b)
{
    if(a.grade!=b.grade)return a.grade>b.grade;
    if(a.yu!=b.yu)return a.yu>b.yu;
    return a.num<b.num;
}

int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        stu[i].num=i+1;
        cin>>stu[i].yu;
        cin>>stu[i].shu;
        cin>>stu[i].ying;
        stu[i].grade=stu[i].yu+stu[i].shu+stu[i].ying;
    }
    sort(stu,stu+n,cmp);
    for(int j=0;j<5;j++)
    {
        cout<<stu[j].num<<" "<<stu[j].grade<<endl;
    }
    system("pause");
    return 0;
}