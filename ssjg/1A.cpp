#include<stdio.h>
#include "stdlib.h"
int main()
{
	int n=0;
	int m=0;
	int count=0; 
	printf("����n��ֵ��m��ֵ:"); 
	scanf("%d%d",&n,&m);
	int a[200]={0};
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			count++;
			if(count>n)count=1;
			if(a[count])j--;
		}
		printf("��%2d���������Ϊ:%d\n",i+1,count);
		a[count]=1;
	}
	system("pause");
	return 0;
}