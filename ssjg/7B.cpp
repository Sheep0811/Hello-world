#include<stdio.h>
#include<stdlib.h>
int n;  //人数

typedef struct {
		int score[100][2];
		int spouse = 0;   //无配偶 

}people;

people boy[100],girl[100];

void Heap_boy(int i,int j,int n) //构建大顶堆
{
	if( 2*j<=n && boy[i].score[2*j][1]>boy[i].score[j][1] )//如果
	 {
		int temp1=boy[i].score[j][0];
		int temp2=boy[i].score[j][1];
		boy[i].score[j][0] = boy[i].score[2*j][0];
		boy[i].score[j][1] = boy[i].score[2*j][1];
		boy[i].score[2*j][0] = temp1;
		boy[i].score[2*j][1] = temp2;
		Heap_boy(i,2*j,n);
	}
	if(2*j+1<=n && boy[i].score[2*j+1][1]>boy[i].score[j][1]) 
	{
		int temp1=boy[i].score[j][0];
		int temp2=boy[i].score[j][1];
		boy[i].score[j][0] = boy[i].score[2*j+1][0];
		boy[i].score[j][1] = boy[i].score[2*j+1][1];
		boy[i].score[2*j+1][0] = temp1;
		boy[i].score[2*j+1][1] = temp2;
		Heap_boy(i,2*j+1,n);
	}
}
void maxHeap_boy() //大顶堆
{
	for(int i = 1 ; i <= n ; ++i)
		for(int j = n ; j > 0 ; --j)
			Heap_boy(i,j,n);
}

void adjust_boy(int i)
{
	boy[i].score[1][0]= boy[i].score[n][0];
	boy[i].score[1][1]= boy[i].score[n][1];
	boy[i].score[n][0] = 0;
	boy[i].score[n][1] = 0; 
	Heap_boy(i,1,n);
}

int Gale_Shapley() 
{
	while(1) 
	{
		int flag = 0;
		for(int i = 1 ; i <= n ; ++i)
		 {
			if(boy[i].spouse == 0 && boy[i].score[1][0] != 0) //男子无配偶
			{
				if(girl[boy[i].score[1][0]].spouse == 0)//如果男生最喜欢的女生无配偶则两人配对
				{
					girl[boy[i].score[1][0]].spouse = i;
					boy[i].spouse = boy[i].score[1][0];
					adjust_boy(i);
				} 
				else 
				{
					if(girl[boy[i].score[1][0]].score[girl[boy[i].score[1][0]].spouse][1]< girl[boy[i].score[1][0]].score[i][1]) 
					//如果女生有配偶但更偏好当前男生，则两人配对
				    {
						boy[girl[boy[i].score[1][0]].spouse].spouse = 0;
						girl[boy[i].score[1][0]].spouse = i;
						boy[i].spouse = boy[i].score[1][0];
						adjust_boy(i);
					}
					else
					{
						adjust_boy(i);
					}
				}
				flag = 1;	
			}
		}
		if(!flag) break;//男子集合都有配偶了则退出
	}
}


int main() {
	printf("欢迎来到今天的相约星期六\n请问男女嘉宾人数为:");
	scanf("%d",&n);  //人数
	printf("\n"); 
	for(int i = 1 ; i <= n ; ++i) {   //输入男
		printf("序号为 %d 的男嘉宾对 %d 位女嘉宾的心动指数分别为:\n",i,n);
		for(int j = 1 ; j <= n ; ++j) 
		{
			boy[i].score[j][0] = j;
			scanf("%d",&boy[i].score[j][1]);
		}
	}
	printf("\n"); 
	for(int i = 1 ; i <= n ; ++i) //输入女
	{  
	    printf("序号为 %d 的女嘉宾对 %d 位男嘉宾的心动指数分别为:\n",i,n);
		for(int j = 1 ; j <= n ; ++j) 
		{
			girl[i].score[j][0] = j;
			scanf("%d",&girl[i].score[j][1]);
		}
	}

	maxHeap_boy();
	Gale_Shapley();

	//printf("\n祝福一对对新人能够一生相守、一世平安、夫唱妇和、白头偕老\n\n在这个庄严的舞台上我宣布:\n\n"); 
	printf("根据稳定婚姻匹配算法:\n\n");
	for(int i = 1 ; i <= n ; ++i) 
	{
		printf("牵手成功的男女嘉宾为：男嘉宾:%d 与 女嘉宾:%d\n\n",i,boy[i].spouse);
	}
    system("pause");
    return 0;
}