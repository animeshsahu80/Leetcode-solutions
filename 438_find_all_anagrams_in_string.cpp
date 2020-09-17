class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char,int> mp1;
        map<char,int> mp2;
        for(char c:p){
            mp1[c]++;
        }
        int l=p.size();
        if(l>s.size())
            return {};
        for(int i=0;i<l;i++){
            mp2[s[i]]++;
        }
        vector<int> res;
        if(mp2==mp1){
            res.push_back(0);
        }
        for(int i=l;i<s.size();i++){
            mp2[s[i]]++;
            mp2[s[i-l]]--;
            if(mp2[s[i-l]]==0)
                mp2.erase(s[i-l]);
            if(mp1==mp2)
                res.push_back(i-l+1);
        }
        return res;
    }
};