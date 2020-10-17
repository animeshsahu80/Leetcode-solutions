class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(auto c:tasks){
            mp[c]++;
        }
        if(n==0)
            return tasks.size();
        priority_queue<int> pq;
        for(auto m:mp){
            pq.push(m.second);
        }
        int res=0;
        while(pq.size()){
            int time=0;
            vector<int> temp;
            for(int i=0;i<=n;i++){
                if(pq.size()){
                    temp.push_back(pq.top()-1);
                    pq.pop();
                    time++;
                }
            }
            for(auto t:temp){
                if(t)
                    pq.push(t);
            }
            if(pq.size())
                res+=n+1;
            else
                res+=time;
        }
        return res;
    }
};