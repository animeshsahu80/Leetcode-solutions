class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n=watchedVideos.size();
        queue<int>q;
        q.push(id);
        map<string,int>mp;
        vector<int> visited(n,0);
        visited[id]=1;
        while(q.size()>0&&level--){
            int n=q.size();
            while(n--){
                int node=q.front();
                q.pop();
                for(int i:friends[node]){
                    if(visited[i]==0){
                        q.push(i);
                        visited[i]=1;
                    }
                }
                
            }
        }
        while(q.size()>0){
            for(auto movie:watchedVideos[q.front()]){
                mp[movie]++;
            }
            q.pop();
        }
        vector<pair<int,string>> vec;
        for(auto node:mp){
            vec.push_back(make_pair(node.second,node.first));
        }
        sort(vec.begin(),vec.end());
        vector<string> ans;
        for(int i=0;i<vec.size();i++){
            ans.push_back(vec[i].second);
        }
        return ans;
    }
};