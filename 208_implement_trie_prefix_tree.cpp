class Trie {
    struct TrieNode{
        char ch;
        int count;
        int ends;
        vector<TrieNode*> child{26};
    };
    TrieNode* root;
    TrieNode* getnode(int index){
        TrieNode* newnode=new TrieNode;
        newnode->ch='a'+index;
        newnode->count=0;
        newnode->ends=0;
        for(int i=0;i<26;i++){
            newnode->child[i]=NULL;
        }
        return newnode;
    }
public:
    /** Initialize your data structure here. */
    Trie() {
        root=getnode('/'-'a');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr=root;
        int index;
        for(auto st:word){
            int index=st-'a';
            if(curr->child[index]==NULL){
                curr->child[index]=getnode(index);
            }
            curr->child[index]->count++;
            curr=curr->child[index];
        }
        curr->ends++;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curr=root;
        int index;
        for(auto st:word){
            index=st-'a';
            if(curr->child[index]==NULL)
                return false;
            curr=curr->child[index];
        }
        if(curr->ends>0)
            return true;
        return false;
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curr=root;
        int index;
        for(auto st:prefix){
            index=st-'a';
            if(curr->child[index]==NULL)
                    return false;
            curr=curr->child[index];
        }
        if(curr->count>0)
            return true;
        return false;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */