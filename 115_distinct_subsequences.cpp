class Solution {
public:
    int numDistinct(string s, string t) {
        long int r=t.size();
        long int c=s.size();
        vector<vector<long int>> dp(r+1,vector<long int>(c+1,0));
        for(int i=0;i<=c;i++){
            dp[0][i]=1;
        }
        for(long int i=1;i<=r;i++){
            for(long int j=1;j<=c;j++){
                if(t[i-1]!=s[j-1]){
                    dp[i][j]=dp[i][j-1];
                }
                else{
                    dp[i][j]=dp[i-1][j-1] + dp[i][j-1];
                }
            }
        }
        return (int)dp[r][c];
    }
};