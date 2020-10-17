class Solution {
public:
    
    bool solve(string s, set<string>& dict,int idx,vector<int>& dp){
        if(idx==s.size())
            return true;
      if(dp[idx]!=-1){
          return dp[idx];
      }
        string temp="";
        for(int i=idx;i<s.size();i++){
            temp+=s[i];
            if(dict.find(temp)!=dict.end() && solve(s,dict,i+1,dp))
                return dp[idx]=1;
        }
        return dp[idx]=0;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict;
        vector<int> dp(s.size(),-1);
        for(auto word:wordDict){
            dict.insert(word);
        }
        bool ans=solve(s,dict,0,dp);
        return ans;
    }
};