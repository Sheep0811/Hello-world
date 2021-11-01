class Solution {
public:
    char firstUniqChar(string s) {
        vector<char> tmp;
        unordered_map<char,int> cot;
        int n=s.size();
        for(char c: s)
        {            
            if(cot.find(c)==cot.end())
            tmp.push_back(c);
            cot[c]++;
        }
        for(char c : tmp)
        {
            if(cot[c]==1)return c;
        }
        return ' ';
    }
};