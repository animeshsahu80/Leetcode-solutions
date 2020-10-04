class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for(int i=0;i<input.size();i++){
            char c=input[i];
            if(c=='*' || c=='+' || c=='-'){
                string left=input.substr(0,i);
                string right=input.substr(i+1);
                vector<int> l=diffWaysToCompute(left);
                vector<int> r=diffWaysToCompute(right);
                for(auto x:l){
                    for(auto y:r){
                        if(c=='-'){
                            res.push_back(x-y);
                        }
                        else if(c=='+'){
                            res.push_back(x+y); 
                        }
                        else
                            res.push_back(x*y);
                    }
                }
            }
        }
        if(res.size()==0){
            res.push_back(stoi(input));
            return res;
        }
            return res;
        
    }
};