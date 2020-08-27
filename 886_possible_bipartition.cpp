class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        map<int,vector<int>> adj;
        for(auto pr:dislikes){
            adj[pr[0]].push_back(pr[1]);
            adj[pr[1]].push_back(pr[0]);
        }
        vector<int> color(N+1,0);
        queue<int> q;
        for(int i=1;i<=N;i++){
            if(color[i]==1|| color[i]==-1)
                continue;
            queue<int> q;
            q.push(i);
            color[i]=1;
            while(q.size()){
                int curr=q.front();
                q.pop();
                for(auto val:adj[curr]){
                    if(color[val]==color[curr])
                        return false;
                    if(color[val]==0){
                        color[val]=-color[curr];
                        q.push(val);
                    }
                }
            }
        }
        return true;
    }
};