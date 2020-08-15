class Solution {
public:
    struct comp{
        bool operator()(pair<int,int>&a, pair<int,int>& b){
            return a.second < b.second;
        }
    };
    
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        map<int,int> mp;
        for(auto num:barcodes){
            mp[num]++;
        }
        priority_queue<pair <int,int>,vector<pair<int,int>>,comp> q;
        for(auto it:mp){
            q.push(make_pair(it.first,it.second));
        }
        vector<int> res;
        while(q.size()>1){
            auto p1=q.top();
            q.pop();
            res.push_back(p1.first);
            auto p2=q.top();
            q.pop();
            res.push_back(p2.first);
            if(p1.second>1){
                q.push(make_pair(p1.first,p1.second-1));
            }
            if(p2.second>1){
                q.push(make_pair(p2.first,p2.second-1));
            }
        }
        if(q.size()>0){
            res.push_back(q.top().first);
        }
        return res;
    }
};