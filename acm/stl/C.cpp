#include<bits/stdc++.h>
using namespace std;
int n,a[400005],b[400005],t[400005];
struct node
{
	int h,bj;
	friend bool operator< (node a1,node b1)
	{
		return a1.h>b1.h;
	}
};

priority_queue<node> q;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];	
	for(int i=1;i<=n;i++)
	{
		node temp;
		temp.h=a[i]+b[++t[i]];
		temp.bj=i;
		q.push(temp);
	    printf("%d\n",q.top().h);	
		int bjt=q.top().bj;
		if(t[bjt]<n)
		{
			temp.h=a[bjt]+b[++t[bjt]];
			temp.bj=bjt;
		}
		q.push(temp);
		q.pop();
	}
    system("pause");
    return 0;
} 
