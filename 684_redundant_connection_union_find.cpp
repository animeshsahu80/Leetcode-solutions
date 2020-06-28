class Solution {
public:
    
    int find(map<int,int>& parent,int val){
        if(parent[val]==val)
            return val;
        int par=find(parent,parent[val]);
        parent[val]=par;
        return par;
    }
    
    
    int union_set(map<int,int>& parent,int u,int v){
        int p1=find(parent,u);
        int p2=find(parent,v);
        if(p1==p2)
            return 0;
        parent[p1]=p2;
        return 1;
        
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        map<int,int> parent;
        vector<int> res;
        for(auto node:edges){
            int u=node[0];
            int v=node[1];
            if(parent.count(u)==0)
                parent[u]=u;
            if(parent.count(v)==0)
                parent[v]=v;
            int flag=union_set(parent,u,v);
            if(flag==0){
                res.push_back(u);
                res.push_back(v);
                break;
            }
        }
        return res;
    }
};