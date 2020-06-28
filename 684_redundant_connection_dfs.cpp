class Solution {
public:
    bool dfs(int src,int dest,vector<vector<int>>& adj,set<int>& visited){
        if(visited.count(src)==1)
            return 0;
        if(src==dest)
            return 1;
        visited.insert(src);
        for(auto i:adj[src]){
            if(dfs(i,dest,adj,visited))
                return 1;
        }
        return 0;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> adj(n+1);
        vector<int> res;
        for(int i=0;i<edges.size();i++){
            set<int> visited;
            int a=edges[i][0];
            int b=edges[i][1];
            if(adj[a].size()>0 && adj[b].size()>0 && dfs(a,b,adj,visited)){
                res.push_back(edges[i][0]);
                res.push_back(edges[i][1]);
                return res;
            }
            visited.clear();
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        return res;
    }
};