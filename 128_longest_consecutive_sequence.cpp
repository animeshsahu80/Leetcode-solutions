class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(auto val:nums){
            s.insert(val);
        }
        int ans=0;
        for(auto val:nums){
            if(s.find(val-1)==s.end()){
                int curr=val;
                int temp=1;
                while(s.find(val+1)!=s.end()){
                    val++;
                    temp++;
                }
                ans=max(temp,ans);
            }
        }
        return ans;
    }
};