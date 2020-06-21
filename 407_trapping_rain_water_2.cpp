class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int r=heightMap.size();
        
        if(r==0)
            return 0;
        int c=heightMap[0].size();
        vector<vector<int>> visited(r, vector<int>(c,0));
        priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i==0 || i==r-1 || j==0 || j==c-1){
                    pq.push(make_pair(-heightMap[i][j],make_pair(i,j)));
                    visited[i][j]=1;
                }
            }
        }
        int row[4]={0,0,1,-1};
        int col[4]={1,-1,0,0};
        int ans=0;
        while(pq.size()>0){
            auto node=pq.top();
            pq.pop();
            int h=-node.first;
            int x=node.second.first;
            int y=node.second.second;
            for(int i=0;i<4;i++){
                int new_x=x+row[i];
                int new_y=y+col[i];
                if(new_x<0 || new_y<0 || new_x>=r || new_y>=c|| visited[new_x][new_y]){
                    continue;
                }
                visited[new_x][new_y]=1;
                if(heightMap[new_x][new_y]<h){
                   ans=ans+(h-heightMap[new_x][new_y]);
                   heightMap[new_x][new_y]=h;
                }
                pq.push(make_pair(-heightMap[new_x][new_y],make_pair(new_x,new_y)));
            }
        }
        return ans;
    }
};