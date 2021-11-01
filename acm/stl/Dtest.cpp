#include<bits/stdc++.h>
using namespace std;
map < string,int > dic;
int n,temp;
int main(){
   scanf("%d",&n);
   getchar();
    for(int i=1;i<=n;i++)
    {
       string ss;
      getline(cin,ss);
      scanf("%d",&temp);
      getchar();
      dic[ss]=temp;
       }
   scanf("%d",&n);
   getchar();
    for(int i=1;i<=n;i++)
    {
       string s1;
      getline(cin,s1);
      printf("%d\n",dic[s1]);
       }
    return 0;   
    }