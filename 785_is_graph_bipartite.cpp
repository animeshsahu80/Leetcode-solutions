class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> visited(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            if(visited[i]==0){
                visited[i]=-1;
                queue<int> q;
                q.push(i);
                while(q.size()){
                    int curr=q.front();
                    q.pop();
                    for(auto node:graph[curr]){
                        if(node==curr)
                            return false;
                        if(visited[node]==0){
                            visited[node]=1-visited[curr];
                            q.push(node);
                        }
                        else if(visited[node]==visited[curr])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};