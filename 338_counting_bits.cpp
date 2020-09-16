class Solution {
public:
    vector<int> countBits(int num) {
        if(num==0)
            return {0};
        if(num==1)
            return {0,1};
        vector<int> res(num+1);
        res[0]=0;
        res[1]=1;
        for(int i=2;i<=num;i++){
            if(i%2==0)
                res[i]=res[i/2];
            else
                res[i]=res[i/2]+1;
        }
        return res;
    }
};