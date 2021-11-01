#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin>>s;
        stack<int>nums;
        int an=1;
        //stack<char>q;
        for(int i=0;i<(int)s.size();i++){
            if(i==0 || i==2 || i==4 || i==6){
                nums.push(an*(s[i]-'0'));
            }
            else if(s[i]=='+' || s[i]=='-')
            {
                if(s[i]=='+')
               an=1; 
                else {an=-1;
                }
            }
                else
                {
                 //¼ÆËã³Ë³ý·¨
                int a=nums.top();
                nums.pop();
                i++;
                int b=s[i]-'0';
                if(s[i-1]=='/')
                {
                    nums.push(a/b);
                }
                else
                {
                    nums.push(a*b);
                }
                }
            }    
        int ans=0;
        while(!nums.empty()){
            ans+=nums.top();
            nums.pop();
        }
        if(ans==24)
        printf("Yes\n");
        else printf("No\n");
        //cout<<ans<<endl;
    }
    system("pause");
    return 0;
}
