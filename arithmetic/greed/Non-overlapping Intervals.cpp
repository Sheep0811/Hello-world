#include<bits/stdc++.h>
using namespace std;
void greed(vector<vector<int>>& intervals,vector<bool>& ans); 
int main()
{
    int n=0;
    cout<<"请输入活动个数：";
    cin>>n;
    vector<vector<int>>intervals(n,vector<int>(n,0));
    vector<bool> a(n,false);
    for(int i=0;i<n;++i)
    {
        cout<<"请输入第"<<i+1<<"个活动的开始与结束时间：";
        cin>>intervals[i][0]>>intervals[i][1];
    }
    greed(intervals,a);
    cout<<"最优活动安排为："<<endl;
    for(int i=0;i<n;++i)
    {
        if(a[i])
        cout<<"["<<intervals[i][0]<<","<<intervals[i][1]<<"] ";
    }
    system("pause");
    return 0;
}

void greed(vector<vector<int>>& intervals,vector<bool>& ans) 
{
    if(intervals.empty())return;
    sort(intervals.begin(),intervals.end(),[](auto&u,auto&v){return u[1]<v[1];});
    int n=intervals.size();
    int right=intervals[0][1];
    ans[0]=true;
    for(int i=1;i<n;++i)
    {
        if(intervals[i][0]>=right)
        {
            ans[i]=true;
            right=intervals[i][1];
        }
        //else
        //{
        //    ans++;
        //}
    }
}