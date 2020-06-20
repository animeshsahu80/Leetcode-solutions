class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>>dist(r,vector<int>(r,INT_MAX));

        queue<pair<int,int>> q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    q.push(make_pair(i,j));
                   dist[i][j]=0;
                }
            }
        }
        int row[4]={1,0,-1,0};
        int col[4]={0,-1,0,1};
        int res=-1;
        vector<vector<int>>visited(r,vector<int>(r,0));
        while(q.size()>0){
            auto node=q.front();
            int x=node.first;
            int y=node.second;
            q.pop();
            for(int i=0;i<4;i++){
                int new_x=x+row[i];
                int new_y=y+col[i];
                if(new_x<0 ||new_y<0 || new_x>=grid.size() || new_y>=grid[0].size() || visited[new_x][new_y] || grid[new_x][new_y])
                    continue;
                visited[new_x][new_y]=1;
                dist[new_x][new_y]=min(dist[x][y]+1,dist[new_x][new_y]);
                res=max(res,dist[new_x][new_y]);
                q.push(make_pair(new_x,new_y));
            }
        }
        return res;
        
    }
};