class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_val=INT_MAX;
        int max_val=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<min_val){
                min_val=prices[i];
            }
            else{
                max_val=max(max_val,prices[i]-min_val);
            }
        }
        return max_val;
    }
};