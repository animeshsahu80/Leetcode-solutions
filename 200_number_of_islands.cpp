class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size();
        if(r==0)
            return 0;
        int c=grid[0].size();
        int count=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'){
                dfs(grid,i,j);
                count++;
                }
            }
        }
        return count;
    }
    
    void dfs(vector<vector<char>>& grid,int r,int c){
        if(r<0 || r>=grid.size() || c>=grid[0].size() || c<0)
            return;
        if(grid[r][c]=='0')
            return;
        grid[r][c]='0';
        dfs(grid,r+1,c);
        dfs(grid,r,c+1);
        dfs(grid,r-1,c);
        dfs(grid,r,c-1);    
    }
};