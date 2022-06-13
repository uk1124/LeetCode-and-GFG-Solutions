class Trie {
private:
    Trie* child[26] = {};
    bool is_end = false;
public:
    Trie() {
        
    }
    
    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if(!node->child[ch]) { 
                node->child[ch] = new Trie(); 
            }
            node = node->child[ch];
        }
        node->is_end = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(char ch : word) {
            ch -= 'a';
            if(!node->child[ch]) { 
                return false; 
            }
            node = node->child[ch];
        }
        return node->is_end;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(char ch : prefix) {
            ch -= 'a';
            if(!node->child[ch]) { 
                return false; 
            }
            node = node->child[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */