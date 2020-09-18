class Solution {
public:
    string removeKdigits(string num, int k) {
        string s;
        stack<int> st;
        for(auto c:num){
            while(st.size()>0 && k>0 && st.top()>c){
                st.pop();
                k--;
            }
            if(st.size()>0 || c!='0')
                st.push(c);
        }
        while(st.size() && k){
            st.pop();
            k--;
        }
        if(st.size()==0)
            return "0";
        while(st.size()){
            char x=st.top();
            s= x+s;
            st.pop();
        }
      //  reverse(s.begin(),s.end());
        return s;
    }
};