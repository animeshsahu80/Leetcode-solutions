class Solution {
public:
    void dfs(int x,int y,vector<vector<int>>& grid,int& count){
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]==0){
            count++;
            return;
        }
        if(grid[x][y]==-1)
                return;
        grid[x][y]=-1;
        dfs(x+1,y,grid,count);
        dfs(x,y+1,grid,count);
        dfs(x-1,y,grid,count);
        dfs(x,y-1,grid,count);
        return;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int count=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid,count);
                    break;
                }
            }
        }
        return count;
    }
};