class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        vector<int>ranks(numCourses);
        for(auto node:prerequisites){
            graph[node[1]].push_back(node[0]);
            ranks[node[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(ranks[i]==0)
                q.push(i);
        }
        vector<int>ans;
        while(q.size()>0){
            int curr=q.front();
            q.pop();
            ans.push_back(curr);
            for(auto temp:graph[curr]){
                ranks[temp]--;
                if(ranks[temp]==0){
                    q.push(temp);
                }     
            }
        }
        vector<int> no;
        if(ans.size()==numCourses)
            return ans;
        else 
            return no;
    }
};