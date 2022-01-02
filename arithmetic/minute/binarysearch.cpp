#include<bits/stdc++.h>
using namespace std;
//二分搜索函数，arr初始升序，len为数组长度，key为搜索的值
int BinarySearch(vector<int> &arr,int key)
{
    int left=0,right=arr.size()-1;
    while(left<=right)
    {
        int mid=(left+right)>>1;
        if(arr[mid]==key)return mid;
        if(arr[mid]>key)right=mid-1;
        else
        left=mid+1;
    }
    return -1;
};

int main()
{
    ios::sync_with_stdio("false");
    cout<<"-二分搜索-\n请输入数组(升序）长度："<<endl;
    int n=0;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;++i)
    {
        arr[i]=i+1;
    }
   // cout<<"请输入数组值：\n";
   // for(int i=0;i<n;++i)
   // {
   //     cout<<"第"<<i+1<<"个数为：";
   //     cin>>arr[i];
   // }
    cout<<"\n请输入要查询的值：";
    int x=0;
    cin>>x;
    clock_t start,end;
    int time1,time2;
    start=clock();
    int tmp=BinarySearch(arr,x);
    end=clock();
    time1=int(end-start);
    start=clock();
    for(int i=0;i<n;++i)
    {
        if(arr[i]==x)break;
    }
    end=clock();
    time2=int(end-start);
    if(tmp>=0)
    {
        cout<<"在数组中的位置为："<<tmp+1<<endl;
        cout<<"二分查找时间为："<<time1<<"ms"<<endl;
        cout<<"顺序查找时间为："<<time2<<"ms"<<endl;
    }
    else cout<<"没找到欸"<<endl;
    system("pause");
    return 0;
}

