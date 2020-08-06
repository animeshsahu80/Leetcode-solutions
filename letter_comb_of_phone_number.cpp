class Solution {
public:
    
    void backtrack(map<int,string>& mp,string& digits,vector<string>& res,string& s,int i){
        if(i==digits.size()){
            res.push_back(s);
            return;
        }
        string temp=mp[digits[i]-'0'];
        for(int j=0;j<temp.size();j++){
            s+=temp[j];
            backtrack(mp,digits,res,s,i+1);
            s.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        map<int,string> mp;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        
        vector<string> res;
        if(digits.size()==0)
            return res;
        string s="";
        backtrack(mp,digits,res,s,0);
        return res;
    }
};