class Solution {
public:
    string replaceSpace(string s) {
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            { 
                s[i]='%'
                s.insert(i,"20");
                n+=2; 
                i+=2;
             }
        }
        return s;
    }
};