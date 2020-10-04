class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> ch;
        stack<int> idx;
        idx.push(-1);
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                ch.push('(');
                idx.push(i);
            }
            else{
                if(ch.size() >0 &&ch.top()=='('){
                    ch.pop();
                    idx.pop();
                    ans=max(ans,i-idx.top());
                }
                else
                    idx.push(i);
            }
        }
        return ans;
    }
};