class Solution {
public:
    bool is_valid(int x,int y,vector<vector<int>>& grid){
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size())
            return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        queue<pair<int,int>> q;
        int count=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j])
                    count++;
                if(grid[i][j]==2)
                    q.push(make_pair(i,j));
            }
        }
        int row[4]={1,0,0,-1};
        int col[4]={0,-1,1,0};
        int ans=0;
        while(q.size()){
            int n=q.size();
            ans++;
            while(n--){
                count--;
                auto curr=q.front();
                q.pop();
                int a=curr.first;
                int b=curr.second;
                for(int i=0;i<4;i++){
                    int x=a+row[i];
                    int y=b+col[i];
                    if(is_valid(x,y,grid) && grid[x][y]==1){
                        grid[x][y]=2;
                        q.push(make_pair(x,y));
                    }
                        
                }  
            }
        }
        if(count)
            return -1;
        return max(0,ans-1);
    }
};