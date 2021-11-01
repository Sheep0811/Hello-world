#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a[80010]; 
    stack<long long> s;
	long long n,i,count=0;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(i=n;i>0;i--)
	{
		while(!s.empty()&&a[i]>a[s.top()])
		{
			s.pop();
		} 
		if(s.empty()) count+=n-i; 
		else count+=s.top()-i-1;
		s.push(i);
	}
	printf("%lld\n",count);
	system("pause");
	return 0;
}
