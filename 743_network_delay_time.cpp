class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        priority_queue<pair<int,int>> pq;
        vector<bool> visited(N+1,false);
        vector<int> distance(N+1,INT_MAX);
        vector<vector<pair<int,int>>> adj(N+1);
        for(auto node:times){
            adj[node[0]].push_back(make_pair(node[1],node[2]));
        }
        pq.push(make_pair(0,K));
        distance[K]=0;
        while(pq.size()){
            auto node=pq.top();
            pq.pop();
            int d=node.first;
            int curr=node.second;
            if(visited[curr])
                continue;
            visited[curr]=1;
            for(auto temp:adj[curr]){
                int temp_d=temp.second;
                int temp_node=temp.first;
                if(visited[temp_node]==0){
                    if(temp_d+distance[curr]<distance[temp_node]){
                       distance[temp_node]=temp_d+distance[curr];
                       pq.push(make_pair(-distance[temp_node],temp_node));
                    }
                }
            }
        }
       int mx=-1;
        for(int i=1;i<=N;i++)
        {
            mx=max(mx,distance[i]);
        }
       
        if(mx==INT_MAX) return -1;
            
        return mx;
    }
};
