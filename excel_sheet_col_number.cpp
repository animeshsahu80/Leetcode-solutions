class Solution {
public:
    int titleToNumber(string s) {
        reverse(s.begin(),s.end());
        long long val=1;
        long long ans=0;
        for(int i=0;i<s.size();i++){
                ans+=val*(s[i]-'A'+1);
                val=val*26;
        }
        return int(ans);
    }
};