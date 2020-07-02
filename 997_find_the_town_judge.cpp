class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<pair<int,int>> vec(N+1,make_pair(0,0));
        
        for(int i=0;i<trust.size();i++){
            vec[trust[i][0]].first++;
            vec[trust[i][1]].second++;
        }
        for(int i=1;i<=N;i++){
            if(vec[i].second==N-1 && vec[i].first==0)
                return i;
        }
        return -1;
    }
};