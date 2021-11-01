#include<bits/stdc++.h>
using namespace std;
const int M=105;
set<int> s[M],se;
int main(){
	int n,m,k;
	scanf("%d %d",&n,&m);
	int num,z;
	for(int i=1;i<=n;i++){
		s[i].clear();
		scanf("%d",&num);
		for(int j=0;j<num;j++){
			scanf("%d",&z);
			s[i].insert(z);
		}
	}
	for(int i=1;i<=m;i++){
		se.insert(i);
	}
	scanf("%d",&k);
	int x,q;
	for(int i=0;i<k;i++){
		set<int> ans=se;
		scanf("%d %d",&x,&q);
		if(x==1){
			for(int j=0;j<q;j++){
				scanf("%d",&z);
				for(set<int>::iterator it=ans.begin();it!=ans.end();){
					if(s[z].find(*it)==s[z].end()){
						ans.erase(it++);
					}
					else{
						it++;
					}
				}
			}
			for(set<int>::iterator it=ans.begin();it!=ans.end();it++){
				printf("%d ",*it);
			}
			printf("\n");
		}
		else{
			for(int j=0;j<q;j++){
				scanf("%d",&z);
				for(set<int>::iterator it=ans.begin();it!=ans.end();){
					if(s[z].find(*it)!=s[z].end()){
						ans.erase(it++);
					}
					else{
						it++;
					}
				}
			}
			for(set<int>::iterator it=ans.begin();it!=ans.end();it++){
				printf("%d ",*it);
			}
			printf("\n");
		}
	}
	return 0;
}