class Solution {
public:
    
    bool dfs(vector<vector<int>>& adj,vector<int>& visited,int curr,int dest){
        if(curr==dest)
            return true;
        visited[curr]=1;
        for(int i=0;i<adj[curr].size();i++){
            if(visited[adj[curr][i]]==0 && dfs(adj,visited,adj[curr][i],dest) )
               return true;
        }
        return false;
    }
    
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for(auto node:prerequisites){
            adj[node[0]].push_back(node[1]);
        }
        vector<bool> vec;
        for(int i=0;i<queries.size();i++){
            vector<int> visited(n,0);
            bool ans=dfs(adj,visited,queries[i][0],queries[i][1]);
            vec.push_back(ans);
        }
        return vec;
    }
};