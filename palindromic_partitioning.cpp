class Solution {
public:
    bool ispal(string s){
        string t=s;
        reverse(t.begin(),t.end());
        if(s==t)
            return true;
        return false;
    }
    
    void solver(string& s,vector<string>& vec,vector<vector<string>>& ans,int idx){
        if(idx>=s.size()){
            ans.push_back(vec);
        }
        for(int i=idx;i<s.size();i++){
            string temp=s.substr(idx,i-idx+1);
            if(ispal(temp)){
                vec.push_back(temp);
                solver(s,vec,ans,i+1);
                vec.pop_back();
            }
        }
        return ;
    }
    
    
    vector<vector<string>> partition(string s) {
        vector<string> vec;
        vector<vector<string>> ans;
        solver(s,vec,ans,0);
        return ans;
    }
};