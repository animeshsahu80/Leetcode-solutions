class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res(n);
        res[0]=1;
        int sign=1;
        for(int i=1;i<n;i++){
            if(k==0){
                res[i]=i+1;
                continue;
            }
            res[i]=res[i-1] + k*sign;
            sign*=-1;
            k--; 
        }
        return res;
    }
};