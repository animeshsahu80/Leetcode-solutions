class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mp;
        vector<vector<string>> res;
        for(int i=0;i<strs.size();i++){
            string temp=strs[i];
            sort(strs[i].begin(),strs[i].end());
            mp[strs[i]].push_back(temp);
        }
        for(auto str:mp){
            vector<string> temp;
            for(auto s:str.second){
                temp.push_back(s);
            }
            res.push_back(temp);
        }
        return res;
    }
};