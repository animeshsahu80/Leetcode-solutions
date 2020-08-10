class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int> mp;
        int ans=0;
        for(int i=0;i<nums.size();i++){
          if(mp.find(nums[i])!=mp.end())
              mp[nums[i]]++;
            else
                mp.insert(make_pair(nums[i],1));
        }
        set<int> s(nums.begin(),nums.end());
        for(auto num:s){
            if(mp[num]>=2){
                ans+= ((mp[num])*(mp[num]-1))/2;
            }
        }
        return ans;
    }
};