class Solution {
public:
    static bool comp(pair<string,int>& a, pair<string,int>b){
        if(a.second!=b.second)
            return a.second> b.second;
        return a.first< b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        vector<pair<string,int>> temp;
        for(auto p:mp){
            temp.push_back(make_pair(p.first,p.second));
        }
        sort(temp.begin(),temp.end(),comp);
        vector<string> res;
        for(auto st:temp){
            res.push_back(st.first);
            if(res.size()==k)
                break;
        }
        return res;
    }
};