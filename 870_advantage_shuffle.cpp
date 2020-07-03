class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int len=A.size();
        vector<int> res(len);
        multiset<int> s(A.begin(),A.end());
        for(int i=0;i<len;i++){
            auto iter=s.upper_bound(B[i]);
            if(iter!=s.end()){
                res[i]=*iter;
                s.erase(iter);
            }
            else{
                res[i]=*(s.begin());
                s.erase(s.begin());
            }
        }
        return res;
    }
};