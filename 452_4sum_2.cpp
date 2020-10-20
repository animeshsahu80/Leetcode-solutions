class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map<int,int> mp1;
        for(int i=0;i<A.size();i++){
            for(int j=0;j<B.size();j++){
                mp1[A[i]+B[j]]++;
            }
        }
        map<int,int> mp2;
        int ans=0;
        for(int i=0;i<C.size();i++){
            for(int j=0;j<D.size();j++){
                int s=C[i]+ D[j];
                if(mp1.find(-s)!=mp1.end()){
                    ans+=mp1[-s];
                }
            }
        }
        return ans;
    }
};