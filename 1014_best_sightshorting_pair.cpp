class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int n=A.size();
        vector<int> res(n);
        vector<int> sum(n);
        sum[0]=A[0];
        int max_num=INT_MIN;
        
        for(int i=1;i<n;i++){
            res[i]=A[i]+sum[i-1] -1;
            max_num=max(max_num,res[i]);
            sum[i]=max(sum[i-1]-1,A[i]);
        }
        return max_num;
    }
};