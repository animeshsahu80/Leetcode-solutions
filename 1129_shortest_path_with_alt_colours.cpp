class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        int visited [n][2];
        memset(visited,-1,sizeof visited);
        
        vector<vector<pair<int,int>>> graph(n);
        for(auto nde: red_edges){
            graph[nde[0]].push_back(make_pair(nde[1],0));
        }
        for(auto nde: blue_edges){
            graph[nde[0]].push_back(make_pair(nde[1],1));
        }
        visited[0][0]=0;
        visited[0][1]=0;
        queue<pair<int,int>> q;
        q.push(make_pair(0,1));
        q.push(make_pair(0,0));
        while(q.size()>0){
            int n=q.size();
            while(n--){
                pair<int, int> curr=q.front();
                q.pop();
                for(auto node: graph[curr.first]){
                    if(visited[node.first][node.second]==-1 && node.second!=curr.second){
                        visited[node.first][node.second]=1+ visited[curr.first][curr.second];
                        q.push(node);
                    }
                }
            }
        }

        vector<int> out;
        for(int i=0;i<n;i++){
            if(min(visited[i][0],visited[i][1])==-1)
                out.push_back(max(visited[i][0],visited[i][1]));
            else
                out.push_back(min(visited[i][0],visited[i][1]));
        }
        return out;
    }
};