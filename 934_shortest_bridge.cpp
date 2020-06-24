class Solution {
public:
    bool is_valid(int x,int y,vector<vector<int>>& A){
        if(x<0 || y<0|| x>=A.size() || y>=A[0].size())
            return false;
        return true;
    }
    void helper(vector<pair<int,int>>& vec,vector<vector<int>>& A,int i,int j,vector<vector<int>>& visited){
        vec.push_back(make_pair(i,j));
        visited[i][j]=1;
        int row[4]={0,0,-1,1};
        int col[4]={1,-1,0,0};
        for(int k=0;k<4;k++){
            int x=row[k]+i;
            int y=col[k]+j;
            if(is_valid(x,y,A)&& A[x][y]&& visited[x][y]==0)
                helper(vec,A,x,y,visited);
        }
    }
    int shortestBridge(vector<vector<int>>& A) {
     int r=A.size();
        if(r==0)
            return 0;
     int c=A[0].size();
     vector<vector<int>> visited(r,vector<int>(c,0));
     vector<pair<int,int>> p;
     vector<pair<int,int>> q;
     for(int i=0;i<r;i++){
         for(int j=0;j<c;j++){
             if(A[i][j]==0)
                 continue;
             if(p.size()==0){
                 helper(p,A,i,j,visited);
             }
             if(q.size()==0&&visited[i][j]==0){
                 helper(q,A,i,j,visited);
             }
         }
     }
        int ans=INT_MAX;
     for(auto i:p){
         for(auto j:q){
             int dist=abs(i.first-j.first)+abs(i.second-j.second)-1;
             ans=min(ans,dist);
         }
     }
        return ans;
    }
