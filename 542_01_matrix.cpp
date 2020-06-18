class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        queue<pair<int,int>> q;
        if(matrix.size()==0)
            return matrix;
        int r=matrix.size();
        int c=matrix[0].size();
        int row[4]={0,1,-1,0};
        int col[4]={1,0,0,-1};
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==0){
                    q.push(make_pair(i,j));
                }
            }
        }
        vector<vector<int>> res;
        for(int i=0;i<r;i++){
            vector<int> vec;
            for(int j=0;j<c;j++){
                vec.push_back(0);
            }
            res.push_back(vec);
        }
        int dist=1;
        while(q.size()>0){
            int n=q.size();
            while(n--){
                pair node=q.front();
                q.pop();
                int x=node.first;
                int y=node.second;
                for(int i=0;i<4;i++){
                    int new_x=x+row[i];
                    int new_y=y+col[i];
                    if(new_x>=0 && new_x<r && new_y>=0 && new_y<c && matrix[new_x][new_y]!=0 && res[new_x][new_y]==0){
                        res[new_x][new_y]=dist;
                        q.push(make_pair(new_x,new_y));
                    }
                }
            }
            dist++;
        }
        return res;
    }
};