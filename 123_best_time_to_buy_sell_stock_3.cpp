class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0)
            return 0;
        vector<int> left(n);
        left[0]=0;
        int min_=prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]<=min_)
                min_=prices[i];
            left[i]=max(left[i-1],prices[i]-min_);
        }
        vector<int> right(n);
        right[n-1]=0;
        int max_=prices[n-1];
        for(int i=n-2;i>=0;i--){
            if(prices[i]>=max_)
                max_=prices[i];
            right[i]=max(right[i+1],max_-prices[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,right[i]+left[i]);
        }
        return ans;
    }
};