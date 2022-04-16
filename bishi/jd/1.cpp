#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

    int lengthOfLongestSubstring(string s);
int main()
{
    cout<<lengthOfLongestSubstring("abc");
	system("pause");
	return 0;
}
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> tmp;
        int n=s.size();
        int ans=0;
        int left=-1;
        for(int i=0;i<n;++i)
        {
            if(tmp.find(s[i])!=tmp.end())
            {
                left=max(tmp[s[i]]+1,left);
            }
            tmp[s[i]]=i;
            ans=max(ans,i-left);
        }
        return ans;
    }

