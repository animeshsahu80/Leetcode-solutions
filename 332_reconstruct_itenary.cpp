class Solution {
public:
    void dfs(unordered_map<string,priority_queue<string,vector<string>,greater<string>>>& mp,vector<string> &res,string s){
        while(mp[s].size()){
            string node=mp[s].top();
            mp[s].pop();
            dfs(mp,res,node);
        }
        res.push_back(s);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,priority_queue<string,vector<string>,greater<string>>> mp;
        for(auto node: tickets){
            mp[node[0]].push(node[1]);
        }
        vector<string> res;
        dfs(mp,res,"JFK");
        if(mp.size()==0)
            return res;
        reverse(res.begin(),res.end());
        return res;
    }
};