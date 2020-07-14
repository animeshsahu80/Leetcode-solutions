class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        map<int,vector<int>>  mp;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                mp[i+j].push_back(matrix[i][j]);
            }
        }
        vector<int>res;
        for(auto pr:mp){
            if(pr.first%2==0){
                reverse(pr.second.begin(),pr.second.end());
            }
            for(auto num:pr.second){
                res.push_back(num);
            }
        }
        return res;
    }
};

