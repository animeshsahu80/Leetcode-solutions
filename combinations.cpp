class Solution {
public:
    void backtrack(vector<int>& inp,vector<vector<int>>& res,vector<int>& sub,int n,int k,int idx){
        if(sub.size()==k){
            res.push_back(sub);
            return;
        }
        for(int i=idx;i<n;i++){
            sub.push_back(inp[i]);
            backtrack(inp,res,sub,n,k,i+1);
            sub.pop_back();
        }
        return;
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> sub;
        vector<int> inp;
        for(int i=1;i<=n;i++){
            inp.push_back(i);
        }
        backtrack(inp,res,sub,n,k,0);
        return res;
    }
};