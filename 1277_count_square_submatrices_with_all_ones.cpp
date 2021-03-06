class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans=0;
        int r=matrix.size();
        int c=matrix[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j])
                    ans++;
            }
        }
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
               if(matrix[i][j]){
                   matrix[i][j]+=min(matrix[i-1][j-1],min(matrix[i-1][j],matrix[i][j-1]));
               } 
            }
        }
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                if(matrix[i][j]>1)
                    ans+=matrix[i][j]-1;
            }
        }
        return ans;
    }
};