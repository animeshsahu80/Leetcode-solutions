class Solution {
public:
    void solver(vector<string>& res,string& out,int open,int close){
        if(open==0 && close==0){
            res.push_back(out);
            return;
        }
        if(open!=0){
            string op1=out;
            out+='(';
       
            solver(res,out,open-1,close);
            out.pop_back();
        
        }
        if(close>open){
            string op2=out;
            out+=')';
            
   
            solver(res,out,open,close-1);
            out.pop_back();
          
        }
        return;
            
    }
    vector<string> generateParenthesis(int n) {
        int open=n;
        int close=n;
        vector<string> res;
        string out="";
        solver(res,out,open,close);
        return res;
    }
};