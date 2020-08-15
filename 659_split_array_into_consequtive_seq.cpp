class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int> mp;
        for(auto num:nums){
            mp[num]++;
        }
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]==0)
                continue;
            int count=0;
            int freq=mp[nums[i]];
            int num=nums[i];
            while(mp.count(num)&& mp[num]>=freq){
                freq=mp[num];
                mp[num]--;
                num++;
                count++;
            }
            if(count<3)
                return false;
        }
        return true;
    }
};