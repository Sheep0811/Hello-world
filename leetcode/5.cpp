class Solution {
public:
    string longestPalindrome(string s) {
        if(s==" ")
        return " ";
        string result(" ");
        for(int i=0;i<s.size();i++){
            string s1=expand(s,i,i);
            string s2=expand(s,i,i+1);
            if(s1.size()>result.size()){
                result=s1;
            }
            if(s2.size()>result.size()){
                result=s2;
            }
        }
        return result;
    }

    string expand(string s,int l,int r)
    {
        int si=s.size();
        while(l>=0 && r<si && s[l]==s[r])
        {
            l--;
            r++;
        }    
        return s.substr(left+1,right-left-1);
    }
};