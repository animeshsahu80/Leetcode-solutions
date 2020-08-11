class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        priority_queue<int> q;
        map<int,int> mp;
        for(auto num:nums){
            mp[num]++;
            q.push(num);
        }
        map<int,int> temp;
        while(q.size()){
            int ans=q.size() - mp[q.top()];
            temp[q.top()]=ans;
            mp[q.top()]--;
            q.pop();
        }
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            res.push_back(temp[nums[i]]);
        }
        return res;
    }
};