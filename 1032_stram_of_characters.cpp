class StreamChecker {
public:
    struct trienode{
        bool end;
        vector<trienode*> child{26};
    };
    trienode* root=new trienode();
    string str="";
    void insert(string word){
        trienode* curr=root;
        for(int i=word.size()-1;i>=0;i--){
            char c=word[i];
            if(curr->child[c-'a']==NULL){
                curr->child[c-'a']=new trienode();
            }
            curr=curr->child[c-'a'];
        }
        curr->end=true;
    }
    StreamChecker(vector<string>& words) {
        for(auto word:words){
            insert(word);
        }
    }
    
    bool query(char letter) {
        str+=letter;
        trienode* curr=root;
        for(int i=str.size()-1;i>=0;i--){
            char c=str[i];
            curr=curr->child[c-'a'];
            if(curr!=NULL && curr->end==true)
                return true;
            if(curr==NULL)
                return false;
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */