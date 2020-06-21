class Solution {
public:
    bool isvalid(vector<vector<int>>& grid, int i,int j){
         int r=grid.size();
        int c=grid[0].size();
        if(i<0 || j<0 || i>=r || j>=c){
            return false;
        }
        return true;
    }
    void dfs(int x,int y,vector<vector<int>>& visited,vector<vector<int>>& grid){
        if(visited[x][y])
            return;
        visited[x][y]=1;
        int up,down,left,right;
        up=left=down=right=0;
        if(grid[x][y]==1)
            left=right=1;
        else if(grid[x][y]==2)
            up=down=1;
        else if(grid[x][y]==3)
            left=down=1;
        else if(grid[x][y]==4)
            right=down=1;
        else if(grid[x][y]==5)
            up=left=1;
        else
            up=right=1;
        if(up){
            int new_x=x-1;
            int new_y=y;
            if(isvalid(grid,new_x,new_y) && (grid[new_x][new_y]==2||grid[new_x][new_y]==3 ||grid[new_x][new_y]==4)){
                dfs(new_x,new_y,visited,grid);
            }        
        }
        if(down){
            int new_x=x+1;
            int new_y=y;
            if(isvalid(grid,new_x,new_y) && (grid[new_x][new_y]==2||grid[new_x][new_y]==5 ||grid[new_x][new_y]==6)){
                dfs(new_x,new_y,visited,grid);
            }        
        }
        if(left){
            int new_x=x;
            int new_y=y-1;
            if(isvalid(grid,new_x,new_y) && (grid[new_x][new_y]==1||grid[new_x][new_y]==4 ||grid[new_x][new_y]==6)){
                dfs(new_x,new_y,visited,grid);
            }        
        }
        if(right){
            int new_x=x;
            int new_y=y+1;
            if(isvalid(grid,new_x,new_y) && (grid[new_x][new_y]==1||grid[new_x][new_y]==3 ||grid[new_x][new_y]==5)){
                dfs(new_x,new_y,visited,grid);
            }        
        }
    }
    
    bool hasValidPath(vector<vector<int>>& grid) {
        int r=grid.size();
        if(r==0)
            return true;
        int c=grid[0].size();
        vector<vector<int>> visited(r,vector<int>(c,0));
        dfs(0,0,visited,grid);
        return visited[r-1][c-1];
    }
};