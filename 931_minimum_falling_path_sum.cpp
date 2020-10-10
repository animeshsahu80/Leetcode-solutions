class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        for(int i=1;i<A.size();i++){
            for(int j=0;j<A[0].size();j++){
                int a=1000;
                int b=1000;
                int c=1000;
                if(j>0)
                    a=A[i-1][j-1];
                
                b=A[i-1][j];
                
                if(j<A[j].size()-1)
                    c=A[i-1][j+1];
                
                
                A[i][j]+=min(a,min(b,c));
            }
        }
        int ans=1000;
        for(int i=0;i<A[0].size();i++)
            ans=min(ans,A[A.size()-1][i]);
        return ans;
    }
};