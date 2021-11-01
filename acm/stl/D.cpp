#include <bits/stdc++.h>
using namespace std;
map<string,int>dic;
int main()
{
    int n,page,m;
    string word,input;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>word>>page;
        dic[word]=page;
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>input;
        cout<<dic[input]<<endl;
    }
    system("pause");
    return 0;   
  }