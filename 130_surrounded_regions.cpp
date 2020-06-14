class Solution {
public:
    void dfs(vector<vector<char>>& board,int i,int j,int r,int c){
        if(i<0 || j<0 || i>r-1 || j>c-1)
            return;
        if(board[i][j]=='V'|| board[i][j]=='X')
            return;
        board[i][j]='V';
        dfs(board,i+1,j,r,c);
        dfs(board,i-1,j,r,c);
        dfs(board,i,j+1,r,c);
        dfs(board,i,j-1,r,c);

    }  
    
    
    void solve(vector<vector<char>>& board) {
        int r=board.size();
        if(r==0)
            return;
        int c=board[0].size();
        for(int i=0;i<r;i++){
            if(board[i][0]=='O'){
                dfs(board,i,0,r,c);
            }
            if(board[i][c-1]=='O'){
                dfs(board,i,c-1,r,c);
            }
        }
        for(int i=0;i<c;i++){
            if(board[0][i]=='O'){
                dfs(board,0,i,r,c);   
            }
            if(board[r-1][i]=='O'){
                dfs(board,r-1,i,r,c);
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='V')
                    board[i][j]='O';
            }
        }
        return ;
    }
};