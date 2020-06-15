class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> uset (wordList.begin(),wordList.end());
        queue<string> q;
        q.push(beginWord);
        int level=1;
        if(uset.find(endWord)==uset.end())
            return 0;
        while(q.size()>0){
            int n=q.size();
            while(n--){
                string word=q.front();
                if(word==endWord)
                    return level;
                q.pop();
                for(int i=0;i<word.size();i++){
                    char c=word[i];
                    for(int j=0;j<26;j++){
                        word[i]='a'+j;
                        if(uset.find(word)!=uset.end()){
                            q.push(word);
                            uset.erase(word);
                        }   
                    }
                    word[i]=c;
                }
            }
            level++;
        }
        return 0;
    }
};