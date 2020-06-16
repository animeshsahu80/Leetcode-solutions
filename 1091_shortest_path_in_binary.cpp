class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row[8]={0,1,-1,0,-1,1,-1,1};
        int col[8]={1,0,0,-1,-1,-1,1,1};
        queue<int>x;
        queue<int>y;
        int n=grid.size();
        
        if(grid[0][0] || grid[n-1][n-1])
            return -1;
        x.push(0);
        y.push(0);
        int ans=0;
        while(x.size()>0&&y.size()>0){
            int l=x.size();
            ans++;
            while(l--){
                int new_x=x.front();
                int new_y=y.front();
                x.pop();
                y.pop();
                if(new_y==n-1&&new_x==n-1)
                    return ans;
                for(int i=0;i<8;i++){
                    int temp_x=new_x + row[i];
                    int temp_y=new_y + col[i];
                    if(temp_x<0 || temp_y<0 ||temp_x>=n || temp_y>=n || grid[temp_x][temp_y]==1)
                        continue;
                    x.push(temp_x);
                    y.push(temp_y);
                    grid[temp_x][temp_y]=1;
                }
            }
        }
        return -1;
    }
};