class WordDictionary {
public:
    struct trienode{
        bool isend=false;
        vector<trienode*> children{26};
        
    };
    trienode* root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root=new trienode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        trienode* temp=root;
        for(int i=0;i<word.size();i++){
            char c=word[i];
            if(temp->children[c-'a']==NULL){
                temp->children[c-'a']=new trienode();
            }
            temp=temp->children[c-'a'];
        }
        temp->isend=true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool solve(string word,int i,trienode* node){
        if(node==NULL)
            return false;
        if(i==word.size())
            return node->isend;
        char c=word[i];
        if(c=='.'){
            for(int k=0;k<26;k++){
                if(solve(word,i+1,node->children[k]))
                    return true;
            }        
        }
        else
            if(solve(word,i+1,node->children[c-'a']))
                return true;
        return false;
    }
    bool search(string word) {
        trienode* temp=root;
        return solve(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */