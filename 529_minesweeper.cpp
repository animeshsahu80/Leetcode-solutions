class Solution {
public:
    
    int count_mines(vector<vector<char>>& board,int i,int j){
        int row[8]={0,1,1,-1,-1,-1,0,1};
        int col[8]={1,0,1,-1,0,1,-1,-1};
        int count=0;
        for(int k=0;k<8;k++){
            if(i+row[k]<0 || i+row[k]>board.size()-1 || j+ col[k]<0 || j+col[k]>board[0].size()-1)
                continue;
            if(board[i+row[k]][j+col[k]]=='M')
                count++;
        }
        return count;
        
    }
    
    
    void dfs(vector<vector<char>>& board,int i,int j){
        if(i<0 || i>board.size()-1 || j<0 || j>board[0].size()-1)
            return ;
        if(board[i][j]!='E')
            return;
        int count=count_mines(board,i,j);
        if(count==0){
            board[i][j]='B';
            int row[8]={0,1,1,-1,-1,-1,0,1};
            int col[8]={1,0,1,-1,0,1,-1,-1};
            for(int k=0;k<8;k++){
                dfs(board,i+ row[k],j+col[k]);
            }
        }
        else{
            board[i][j]=count+ '0';
        }
    }
    
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int i=click[0];
        int j=click[1];
        
        if(i<0 || i>board.size()-1 || j<0 || j>board[0].size()-1)
            return board;
        
        if(board[i][j]=='M'){
            board[i][j]='X';
            return board;
        }
        dfs(board,i,j);
        return board;
    }
};