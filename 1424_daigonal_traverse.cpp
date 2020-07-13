class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        vector<int> ans;
        while(q.size()>0){
            auto node=q.front();
            int i=node.first;
            int j=node.second;
            int n=q.size();
            q.pop();
            ans.push_back(nums[i][j]);
        
                if(j==0&&i+1<nums.size() && nums[i+1].size()>j){
                    q.push(make_pair(i+1,j));
                }
                if(j+1<nums[i].size())
                    q.push(make_pair(i,j+1));
        }
        return ans;
    }
};