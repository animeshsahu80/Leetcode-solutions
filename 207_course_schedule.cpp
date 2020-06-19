




class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> ranks(numCourses,0);
        for(auto node:prerequisites){
            graph[node[1]].push_back(node[0]);
            ranks[node[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(ranks[i]==0)
                q.push(i);
        }
        int ans=numCourses;
        while(q.size()>0){
            int curr=q.front();
            q.pop();
            ans--;
            for(auto temp:graph[curr]){
                ranks[temp]--;
                if(ranks[temp]==0){
                    q.push(temp);
                }
            }
        }
        return !ans;
        
    }
};