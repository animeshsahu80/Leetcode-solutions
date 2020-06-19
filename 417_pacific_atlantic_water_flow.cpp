class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int r=matrix.size();
        
        vector<vector<int>>out;
        if(r==0){
            return out;
        }
        int c=matrix[0].size();
        vector<vector<int>> pacific(r,vector<int> (c, 0));
        vector<vector<int>> atlantic(r,vector<int> (c,0)); 
        for(int i=0;i<c;i++){
            dfs(matrix,0,i,INT_MIN,pacific);
            dfs(matrix,r-1,i,INT_MIN,atlantic);
        }
        for(int i=0;i<r;i++){
            dfs(matrix,i,0,INT_MIN,pacific);
            dfs(matrix,i,c-1,INT_MIN,atlantic);
        }
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(pacific[i][j]==-1&&atlantic[i][j]==-1){
                   vector<int> vec;
                   vec.push_back(i);
                   vec.push_back(j);
                   out.push_back(vec);
                }
            }
        }
        return out;
    }
    void dfs(vector<vector<int>>& matrix,int row,int col,int prev,vector<vector<int>>& ocean){
        if(row<0 || col<0 || row>=matrix.size() || col>=matrix[0].size())
            return;
        if(matrix[row][col]< prev)
            return;
        if(ocean[row][col]==-1)
            return;
        ocean[row][col]=-1;
        dfs(matrix,row+1,col,matrix[row][col],ocean);
        dfs(matrix,row-1,col,matrix[row][col],ocean);
        dfs(matrix,row,col+1,matrix[row][col],ocean);
        dfs(matrix,row,col-1,matrix[row][col],ocean);
    }
};