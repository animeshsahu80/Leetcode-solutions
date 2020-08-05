class Solution {
public:
    void helper(set<int>& res,int low,int high,int idx){
        if(idx>9)
            return;
        int ans=0;
        for(int i=idx;i<=9;i++){
            ans=ans*10 + i;
            if(ans>=low && ans<=high)
                res.insert(ans);
        }
        helper(res,low,high,idx+1);
        return;
    }
    vector<int> sequentialDigits(int low, int high) {
        set<int> res;
        helper(res,low,high,0);
        vector<int> ret;
        for(auto num:res){
            ret.push_back(num);
        }
        return ret;
    }
};