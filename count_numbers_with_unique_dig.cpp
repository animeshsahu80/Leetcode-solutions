class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> res={9,9,8,7,6,5,4,3,2,1};
        int ans=1;
        for(int i=1;i<=n;i++){
            int temp=1;
            for(int j=0;j<i;j++){
                temp=temp*res[j];
            }
            ans+=temp;
        }
        return ans;
    }
    
};