class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return dfs(postorder,0,postorder.size()-1);
    }
    bool dfs(vector<int>& postorder,int l,int r)
    {
        if(l>=r)return true;
        int q=l;
        while(postorder[q]<postorder[r])
        {
            ++q;
        }        
        int left=q-1;
        while(postorder[q]>postorder[r])
        {
            ++q;
        }
        if(q<r)return false;
        return dfs(postorder,l,left) && dfs(postorder,left+1,r-1);
    }
};