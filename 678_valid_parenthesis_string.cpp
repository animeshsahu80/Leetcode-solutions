class Solution {
public:
    bool checkValidString(string s) {
        stack<int> s1;
        stack<int> s2;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                s1.push(i);
            }
            else if(s[i]==')'){
                if(s1.size()>0){
                    s1.pop();
                }
                else if(s2.size()>0){
                    s2.pop();
                }
                else
                    return false;
            }
            else
                s2.push(i);
        }
        while(s1.size()&& s2.size()){
            int val=s2.top();
            s2.pop();
            if(s1.top()<val){
                s1.pop();
            }
        }
        if(s1.size()>0)
            return false;
        return true;
    }
};