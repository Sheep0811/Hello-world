class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int> in;
        string ans="";
        for(int i=0;i<paths.size();++i)
        {
            in[paths[i][0]]++;
        }
        for(int i=0;i<paths.size();++i)
        {
            if(in.find(paths[i][1])==in.end())return paths[i][1];
        }
        return ans;
    }
};