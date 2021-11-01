#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,m,x,k,num,type;
set<int>s[N],quanji,ans;
set<int>::iterator it;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>num;
        for(int j=1;j<=num;j++){
            cin>>x;//选手i做过的题号为x(题目必须去重)
            s[i].insert(x);
        }
    }
    for(int i=1;i<=m;i++)
        quanji.insert(i);//预处理全集
    cin>>k;
    while(k--){
        cin>>type>>num;
        ans=quanji;//两个set之间可以用等于号赋值
        if(type==0){//比赛，他要保证所出的题都没有被任何一个参赛学生做过
            for(int i=1;i<=num;i++){
                cin>>x;//选手编号为x
                for(it=ans.begin();it!=ans.end();){
                    if(s[x].count(*it))ans.erase(it++);//筛掉选手x做过的所有题
                    else it++;
                }
            }
        }
        else{//训练，他要保证所出的题都被每一个参赛学生做过
            for(int i=1;i<=num;i++){
                cin>>x;//选手编号为x
                for(it=ans.begin();it!=ans.end();){
                    if(!s[x].count(*it))ans.erase(it++);//筛掉选手x没做过的所有题
                    else it++;
                }
            }
        }
        for(it=ans.begin();it!=ans.end();it++)
            printf("%d ",*it);
        printf("\n");
    }
    return 0;
}