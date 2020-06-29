class Solution {
public:
    void dfs(set<int>& visited,int src,vector<vector<int>>& rooms){
        visited.insert(src);
        for(auto room:rooms[src]){
            if(visited.count(room)==0)
                dfs(visited,room,rooms);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int> visited;
        dfs(visited,0,rooms);
        if(visited.size()==rooms.size())
            return true;
        return false;
    }
};