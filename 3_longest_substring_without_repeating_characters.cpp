class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int ans=1;
        if(s.size()==0)
            return 0;
        set<char> hs;
        while(r<s.size()){
            if(hs.find(s[r])==hs.end()){
                hs.insert(s[r]);
                int x=hs.size();
                ans=max(ans,x);
                r++;
            }
            else{
                hs.erase(s[l]);
                l++;
            }
                
        }
        return ans;
        
    }
};