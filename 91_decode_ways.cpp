class Solution {
public:
    int numDecodings(string A) {
 int n=A.size();
    if(A[0]=='0')
        return 0;
    vector<int> dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        int d=A[i-1]-'0';
        int dd=(A[i-2]-'0')*10 + d;
        if(d>0)
            dp[i]=dp[i-1];
        if(dd>9 && dd<27)
            dp[i]+=dp[i-2];
    }
    return dp[n];
    }
};