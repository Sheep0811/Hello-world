#include<stdio.h>
#include<stdlib.h>
int main()
{
	int m;
	printf("请输入魔方阵的行数m(奇数）:");
	scanf("%d",&m);
	if(m%2!=1)
	printf("输入的行数m有误\n"); 
	else
	{
    int a[100][100];
		//memset(a, 0, sizeof(a));
		int count=1;
		int i=0;
		int j=(m-1)/2;
		a[i][j]=1;
		a[m-1-i][m-1-j]=m*m;
		for(count=2 ; count<=(m*m+1)/2 ; count++)
		{
			if((count-1)%m==0)i++;
			else
			{
				i--;
				i=(i+m)%m;
				j--;
				j=(j+m)%m;
			}
			a[i][j]=count;
			a[m-1-i][m-1-j]=m*m+1-count;
		}
		for(i=0;i<m;i++)
		{
			for(j=0;j<m;j++)
			{
				printf("%3d",a[i][j]);
			}
		printf("\n");
	}
}system("pause");
return 0;
}