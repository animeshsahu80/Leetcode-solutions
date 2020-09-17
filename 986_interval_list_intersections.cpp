class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int i=0;
        int j=0;
        int a=A.size();
        int b=B.size();
        vector<vector<int>>res;
        while(i<a && j<b){
            int left=max(A[i][0],B[j][0]);
            int right=min(A[i][1],B[j][1]);
            
            if(left<=right){
                res.push_back({left,right});
            }
            if(right==A[i][1])
                i++;
            else if(right==B[j][1])
                j++;
        }
        return res;
        
    }
};