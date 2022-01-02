#include<bits/stdc++.h>
using namespace std;
void greed(vector<vector<int>>& intervals,vector<bool>& ans); //活动安排算法
int nums=0;//不冲突的活动个数
int n=0;//活动个数
int main()
{
    vector<vector<int>>intervals;
    vector<bool> a(1000,false);
    int x;
    cout<<"请选择输入方式：\n1.从文件activity.txt中输入\n2.手动输入\n";
    cin>>x;
    if(x==1)
    {
        ifstream input("activity.txt");
        if (!input)
	    {
		    cout << "文件不存在" << endl;
		    cout << "退出程序" << endl;
            system("pause");
		    return 0;
        }
        input>>n;
        for(int i=0;i<n;++i)
        {
            intervals.push_back(vector<int>(2,0));
            input>>intervals[i][0]>>intervals[i][1];
        }
        input.close();
    }
    else if(x==2)
    {
        cout<<"请输入活动个数：";
        cin>>n;
        for(int i=0;i<n;++i)
        {
            cout<<"请输入第"<<i+1<<"个活动的开始与结束时间：";
            intervals.push_back(vector<int>(2,0));
            cin>>intervals[i][0]>>intervals[i][1];
        }
    }
    else
    {
        cout<<"输入错误，退出程序";
        system("pause");
        return 0;
    }
    greed(intervals,a);
    cout<<"最优活动个数为："<<nums<<"个"<<endl;
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
    nums++;
    for(int i=1;i<n;++i)
    {
        if(intervals[i][0]>=right)
        {
            ans[i]=true;
            nums++;
            right=intervals[i][1];
        }
        //else
        //{
        //    ans++;
        //}
    }
}