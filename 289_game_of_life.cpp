class Solution {
public:
    
    int count(vector<vector<int>>& board,int x,int y,int old1now0,int old0now1){
        vector<vector<int>>dir={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
        int ret=0;
        for(auto point:dir){
            int new_x=x+point[0];
            int new_y=y+point[1];
            if(new_x>=0 && new_x<board.size() && new_y>=0 && new_y<board[0].size()&&(board[new_x][new_y]==1 || board[new_x][new_y]==old1now0)){
                ret++;
            }
        }
        
        return ret;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int old1now0=-1;
        int old0now1=-2;
        int r=board.size();
        int c=board[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int nc=count(board,i,j,old1now0,old0now1);
                if(board[i][j]==1){
                    if(nc<2 || nc>3)
                        board[i][j]=old1now0;
                }
                else if(board[i][j]==0){
                    if(nc==3)
                        board[i][j]=old0now1;
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]==old0now1){
                    board[i][j]=1;
                }
                else if(board[i][j]==old1now0){
                    board[i][j]=0;
                }
            }
        }

    }
};