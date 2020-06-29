class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int count=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1 && is_true(grid,i,j))
                    count++;
            }
        }
        return count;
    }
    bool is_true(vector<vector<int>>& grid,int p,int q){
        int r=grid.size();
        int c=grid[0].size();
        for(int i=0;i<r;i++){
           if(grid[i][q]==1&& i!=p){
               return true;
           }
        }
        for(int i=0;i<c;i++){
            if(grid[p][i]==1&& i!=q)
                return true;
        }
        return false;
    }
};