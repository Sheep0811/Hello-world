class Solution {
public:
    map<char,string>M=
    {
        {'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}
    };
    vector<string>ans;
    string cur;
    void dfs(int index ,string digits)
    {
        if(index==digits.size())
        {
            ans.push_back(cur);
            return;
        }
    for(int i=0;i<M[digits[index]].size();i++)
    {
        cur+=M[digits[index]][i];
        dfs(index++,digits);
        cur.pop_back();
    }
    }
    vector<string> letterCombinations(string digits) {
    if(digits.size()==0) return ans;
    dfs(0,digits);
    return ans;
    }
};