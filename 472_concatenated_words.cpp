class Solution {
public:
    bool exist(string str,set<string>& s){
        for(int i=1;i<str.size();i++){
            string suffix=str.substr(0,i);
            if(s.find(suffix)!=s.end() && (s.find(str.substr(i))!=s.end() || exist(str.substr(i),s)))
               return true;
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        set<string> s;
        for(auto word:words){
            s.insert(word);
        }
        vector<string> res;
        for(auto word:words){
            if(exist(word,s)){
                res.push_back(word);
            }
        }
        return res;
    }
};