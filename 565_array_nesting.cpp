class Solution {
public:
    void dfs(int start,set<int>& visited,vector<int>& nums){
        if(visited.find(start)!=visited.end()){
            return;
        }
        depth++;
        visited.insert(start);
        dfs(nums[start],visited,nums);
    }
    
    int depth;
    int arrayNesting(vector<int>& nums) {
        set<int> visited;
        int l =nums.size();
        int ans=0;
        for(int i=0;i<l;i++){
            if(visited.find(nums[i])==visited.end()){
                depth=0;
                dfs(nums[i],visited,nums);
                ans=max(depth,ans);
            }
        }
        return ans;
    }
};