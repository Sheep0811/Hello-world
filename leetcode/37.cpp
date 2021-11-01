class Solution {
private:
    bool check(vector<vector<char>>& board,int row,int col,char val)
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==val)return false;
        }
        for(int j=0;j<9;j++)
        {
            if(board[j][col]==val)return false;
        }
        int x=(row/3)*3;
        int y=(col/3)*3;
        for(int i=x;i<x+3;i++)
        {
            for(int j=y;j<y+3;j++)
            {
                if(board[i][j]==val)return false;
            }
        }
        return true;
    }
    bool dfs(vector<vector<char>>&board)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')continue;
                for(char k='1';k<='9';k++)
                {
                    if(!check(board,i,j,k))continue;
                    board[i][j]=k;
                    if(dfs(board))return true;
                    board[i][j]='.';
                }                            
                return false;
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board);
    }
};