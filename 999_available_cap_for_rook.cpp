class Solution {
public:
    int solve(int x,int y,vector<vector<char>>& board){
        int r=board.size();
        int c=board[0].size();
        int n=0,e=0,s=0,w=0;
        if(x>0){
            for(int i=x;i>0;i--){
                if(board[x][i]=='p'){
                    e=1;
                    break;
                }
                if(board[x][i]=='B'){
                    break;
                }
            }
        }
        if(y>0){
            for(int i=y;i>0;i--){
                if(board[i][y]=='p'){
                    n=1;
                    break;
                }
                if(board[i][y]=='B'){
                    break;
                }
            }
        }
        if(x<c-1){
            for(int i=x;i<c;i++){
                if(board[x][i]=='p'){
                    w=1;
                    break;
                }
                if(board[x][i]=='B'){
                    break;
                }
            }
        }
        if(y<r-1){
            for(int i=y;i<r;i++){
                if(board[i][y]=='p'){
                    s=1;
                    break;
                }
                if(board[i][y]=='B'){
                    break;
                }
            }
        }
        return n+w+e+s;
    }
    
    
    int numRookCaptures(vector<vector<char>>& board) {
        int ans;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='R'){
                    ans=solve(i,j,board);
                }
            }
        }
        return ans;
    }
};