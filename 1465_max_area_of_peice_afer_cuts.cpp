class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long int m=horizontalCuts.size();
        long int n=verticalCuts.size();
        int MOD=1000000007;
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int h_max=0;
        for(int i=0;i<=m;i++){
            if(i==0)
                h_max=max(h_max,horizontalCuts[i]);
            else if(i==m)
                h_max=max(h_max,h-horizontalCuts[i-1]);
            else
                h_max=max(h_max,horizontalCuts[i]-horizontalCuts[i-1]);
        }
        int w_max=0;
        for(int i=0;i<=n;i++){
            if(i==0)
                w_max=max(w_max,verticalCuts[i]);
            else if(i==n)
                w_max=max(w_max,w-verticalCuts[i-1]);
            else
                w_max=max(w_max,verticalCuts[i]-verticalCuts[i-1]);
        }
        long long int ans=(long(w_max)%MOD)*(long(h_max)%MOD);
        return ans%MOD;
    }
};