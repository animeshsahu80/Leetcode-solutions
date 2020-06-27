class Solution {
public:
    
    double dfs(unordered_map<string, vector<pair<string,double>>>& adj,string src,string dest,set<string>& visited){
        if(src==dest){
            return 1.0;
        }
        double ans=-1;
        visited.insert(src);
        for(auto node:adj[src]){
            if(visited.find(node.first)==visited.end()){
                double t=dfs(adj,node.first,dest,visited);
                if(t!=-1){
                    ans=node.second*t;
                }
            }
            
        }
        return ans;
        
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries){
        unordered_map<string, vector<pair<string,double>>> adj;
        for(int i=0;i<equations.size();i++){
            adj[equations[i][0]].push_back(make_pair(equations[i][1],values[i]));
            adj[equations[i][1]].push_back(make_pair(equations[i][0],1.0/values[i]));
        }
        
        vector<double> res;
        set<string> visited;
        for(int i=0;i<queries.size();i++){
            visited.clear();
            if(adj.find(queries[i][0])==adj.end() && adj.find(queries[i][1])==adj.end()){
                res.push_back(-1);
            }
            else{
                res.push_back(dfs(adj,queries[i][0],queries[i][1],visited));
            }
        }
        return res;
    }
};