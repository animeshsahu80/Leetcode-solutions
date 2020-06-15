class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> deg(n);
        for(int i=0;i<n;i++){
            deg[i]=adj[i].size();
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(deg[i]<=1)
                q.push(i);
        }
        while(n>2){
            int nodes=q.size();
            n=n-nodes;
            while(nodes--){
              int temp=q.front();
                q.pop();
                for(int i=0;i<adj[temp].size();i++){
                    deg[adj[temp][i]]--;
                    if(deg[adj[temp][i]]==1)
                        q.push(adj[temp][i]);
                }
            }
        }
        vector<int> ans;
        while(q.size()>0){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};