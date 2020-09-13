class Solution {
public:
    int solve(int n,vector<int>& mem){
        if(n<0)
            return INT_MAX;
        if(n==0)
            return 0;
        if(mem[n]>0)
            return mem[n];
        int ans=n;
        for(int i=1;i*i<=n;i++){
            ans=min(ans,solve(n-(i*i),mem));
        }
        mem[n]=ans+1;
        return ans+1;
    }
    int numSquares(int n) {
        vector<int> mem(n+1,-1);
        int ret=solve(n,mem);
        return ret;
    }
};