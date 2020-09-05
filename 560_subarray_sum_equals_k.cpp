class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> cum=nums;
        int n=nums.size();
        for(int i=1;i<n;i++){
            cum[i]+=cum[i-1];        
        }
        map<int,int> mp;
        mp[0]=1;
        int ans=0;
        for(int i=0;i<n;i++){
            if(mp.find(cum[i]-k)!=mp.end()){
                ans+=mp[cum[i]-k];
            }
            mp[cum[i]]++;
        }
        return ans;
    }
};