class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> last(26,0);
        for(int i=0;i<S.size();i++){
            last[S[i]-'a']=i;
        }
        
        int start=0;
        int end=0;
        vector<int> res;
        for(int i=0;i<S.size();i++){
            end=max(end,last[S[i]-'a']);
            if(end==i){
                res.push_back(end-start+1);
                start=i+1;
            }
        }
        return res;
    }
};