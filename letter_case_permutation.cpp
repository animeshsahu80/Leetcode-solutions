class Solution {
public:
    void backtrack(string& out,vector<string>& res,string& S,int i){
        if(i==S.size()){
            res.push_back(out);
            return;
        }
        char x=S[i];
       if(isalpha(x)){
           out+=tolower(x);
           backtrack(out,res,S,i+1);
           out.pop_back();
           out+=toupper(x);
           backtrack(out,res,S,i+1);
           out.pop_back();
       }
        else{
            out+=x;
            backtrack(out,res,S,i+1);
            out.pop_back();
            
        }
        return;
    }
    
    vector<string> letterCasePermutation(string S) {
        string out="";
        vector<string> res;
        backtrack(out,res,S,0);
        return res;
    }
};