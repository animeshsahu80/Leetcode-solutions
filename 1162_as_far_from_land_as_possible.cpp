class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j,int dist){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || (grid[i][j]>0&&grid[i][j]<=dist))
           return;
           grid[i][j]=dist;
           dfs(grid,i+1,j,dist+1);
           dfs(grid,i,j+1,dist+1);
           dfs(grid,i-1,j,dist+1);
           dfs(grid,i,j-1,dist+1);
    }
    int maxDistance(vector<vector<int>>& grid) {
       int r=grid.size();
       int c=grid[0].size();
       for(int i=0;i<r;i++){
           for(int j=0;j<c;j++){
               if(grid[i][j]==1){
                   grid[i][j]=0;
                   dfs(grid,i,j,1);
               }
           }
       }
        int mn=-1;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]-1>=mn)
                    mn=grid[i][j]-1;
            }
        }
        if(mn==0)
            return -1;
        return mn;
    }
};