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
            cin>>x;//ѡ��i���������Ϊx(��Ŀ����ȥ��)
            s[i].insert(x);
        }
    }
    for(int i=1;i<=m;i++)
        quanji.insert(i);//Ԥ����ȫ��
    cin>>k;
    while(k--){
        cin>>type>>num;
        ans=quanji;//����set֮������õ��ںŸ�ֵ
        if(type==0){//��������Ҫ��֤�������ⶼû�б��κ�һ������ѧ������
            for(int i=1;i<=num;i++){
                cin>>x;//ѡ�ֱ��Ϊx
                for(it=ans.begin();it!=ans.end();){
                    if(s[x].count(*it))ans.erase(it++);//ɸ��ѡ��x������������
                    else it++;
                }
            }
        }
        else{//ѵ������Ҫ��֤�������ⶼ��ÿһ������ѧ������
            for(int i=1;i<=num;i++){
                cin>>x;//ѡ�ֱ��Ϊx
                for(it=ans.begin();it!=ans.end();){
                    if(!s[x].count(*it))ans.erase(it++);//ɸ��ѡ��xû������������
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