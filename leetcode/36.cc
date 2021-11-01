bool isValidSudoku(char** board, int boardSize, int* boardColSize){
int col=*boardColSize;
int row=boardSize;
int x,y,i,j,a,b;
int sx,sy;
for(x=0;x<row;x++){
    for(y=0;y<col;y++){
        if(board[x][y]!='.'){
            for(j=0;j<row;j++){
                if(j!=x && board[j][y]==board[x][y])
                return false;
            }       
            for( i=0;i<col;i++){
                if(i!=y&&board[x][i]==board[x][y])
                return false;
            }
            sx=x/3*3;
            sy=y/3*3;
            for( a=0;a<3;a++){
                for( b=0;b<3;b++){
                    if(sx+a!=x && sy+b!=i && board[sx+a][sy+b]==board[x][y])
                    return false;
                }
            }
        }
    } 
}
}