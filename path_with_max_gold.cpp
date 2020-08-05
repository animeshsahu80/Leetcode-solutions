class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>& visited){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0 || visited[i][j]==true)
            return 0;
        
        visited[i][j]=true;
        int a=dfs(grid,i+1,j,visited);
        int b=dfs(grid,i-1,j,visited);
        int c=dfs(grid,i,j+1,visited);
        int d=dfs(grid,i,j-1,visited);
        visited[i][j]=false;
        return grid[i][j] + max(a,max(b,max(c,d)));
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=INT_MIN;
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    ans=max(ans,dfs(grid,i,j,visited));
                }
            }
        }
        return ans;
    }
};