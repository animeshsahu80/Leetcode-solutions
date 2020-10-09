class Solution {
public:
    
    void permutation(vector<int>& arr,vector<int>& temp,vector<vector<int>>& res,vector<bool>& used){
        if(temp.size()==arr.size()){
            res.push_back(temp);
            return;
        }
        
        for(int i=0;i<arr.size();i++){
            if(used[i])
                continue;
            temp.push_back(arr[i]);
            used[i]=true;
            permutation(arr,temp,res,used);
            temp.pop_back();
            used[i]=false;
        }
        return;
    }
    bool isvalid(string curr){
        if(curr[0]=='0'){
            if(curr[2]<'5')
                return true;
        }
            
        if(curr[0]>'2')
            return false;
        if(curr[0]=='2'){
            if(curr[1]>'3')
                return false;
        }
        if(curr[2]>'5')
            return false;
        return true;
    }
    string largestTimeFromDigits(vector<int>& arr) {
        vector<int> temp;
        vector<vector<int>> res;
        vector<bool> used(arr.size(),false);
        permutation(arr,temp,res,used);
        vector<string> str;
        for(auto vec:res){
            string curr="";
            for(int i=0;i<vec.size();i++){
                curr+= to_string(vec[i]);
            }
            if(isvalid(curr))
                str.push_back(curr);
        }
        sort(str.begin(),str.end());
        string ans="";
        if(str.size()){
            string s=str[str.size()-1];
            ans=s.substr(0,2) + ':' + s.substr(2);
        
        }
        return ans;
    }
};