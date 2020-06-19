class Solution {
public:
    void dfs(int src,int dst,int K,vector<int>& visited,vector<vector<pair<int,int>>>&graph,int& fare,int cost){
        if(K<-1)
            return;
        if(src==dst){
            fare=min(fare,cost);
            return;
        }
        visited[src]=1;
        for(int i=0;i<graph[src].size();i++){
            if(visited[graph[src][i].first]==0 && (cost+graph[src][i].second)<=fare){
                dfs(graph[src][i].first,dst,K-1,visited,graph,fare,cost+graph[src][i].second);
            }
        }
        visited[src]=0;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int,int>>> graph(n);
        for(auto node: flights){
            graph[node[0]].push_back(make_pair(node[1],node[2]));
        }
        vector<int> visited(n,0);
        int fare=INT_MAX;
        dfs(src,dst,K,visited,graph,fare,0);
        if(fare==INT_MAX)
            return -1;
        return fare;
    }
};