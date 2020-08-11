class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> res(26,0);
        for(int i=0;i<A[0].size();i++){
            res[A[0][i]-'a']++;
        }
        for(int i=1;i<A.size();i++){
            vector<int> temp(26,0);
            string s=A[i];
            for(int j=0;j<s.size();j++){
                temp[s[j]-'a']++;
            }
            for(int j=0;j<26;j++){
                res[j]=min(temp[j],res[j]);
            
            }
        }
        vector<string> ans;
        for(int i=0;i<26;i++){
            while(res[i]--){
                char c=i + 'a';
                string s;
                s=i+'a';
                ans.push_back(s);
            }
        }
        return ans;
    }
};