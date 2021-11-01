#include <bits/stdc++.h>
using namespace std;
struct node
{
       string ID;
       vector < string > web;
};
int main()
{
    vector < node > vec;
    int n,m;
    cin>>n>>m;
    string ID,web;
    for(int i=1;i<=m;i++)
    {
      cin>>ID>>web;
       bool flag =0;
       for(int j=0;j < vec.size(); j++)
         if(vec[j].ID==ID)
          {
            vec[j].web.push_back(web);
            flag=1;
             break;
             }
       if( ! flag)
       {
          node newone;
         newone.ID   =ID;
         newone.web.clear();
         newone.web.push_back(web);
         vec.push_back(newone);
        }
    }
    for(int i=0;i < vec.size();i++)
    {
       cout << vec[i].ID;
       for(int j=0;j < vec[i].web.size();j++)
       {
           cout << " " << vec[i].web[j];
       }
       cout << endl;    
       }
       system("pause");
    return 0;
}

