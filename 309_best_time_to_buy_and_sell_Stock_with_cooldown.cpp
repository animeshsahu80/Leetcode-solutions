class Solution {
public:
    int solve(map<pair<int,int>,int>& mp,int idx,int bos,vector<int>& prices){
    
        if(idx>=prices.size()){
            return 0;
        }
        if(mp.find({idx,bos})!=mp.end())
            return mp[{idx,bos}];
        int x=0;
        if(bos==0){
            int buy=solve(mp,idx+1,1,prices)-prices[idx];
            int nobuy=solve(mp,idx+1,0,prices);
            x=max(buy,nobuy);
        }
        else{
            int sell=solve(mp,idx+2,0,prices)+prices[idx];
            int nosell=solve(mp,idx+1,1,prices);
            x=max(sell,nosell);
        }
        mp[{idx,bos}]=x;
        return x;
    }
    
    
    int maxProfit(vector<int>& prices) {
        
        map<pair<int,int>,int> mp;
        int ans=solve(mp,0,0,prices);
        return ans;
    }
};