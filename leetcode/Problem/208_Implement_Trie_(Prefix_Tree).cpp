class Trie {
public:
    struct TrieNode {
        bool flag;
        map<char, TrieNode*> next;
    };

    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (char&c : word) {
            if ((cur->next)[c] == nullptr) (cur->next)[c] = new TrieNode();
            cur = (cur->next)[c];
        }
        cur->flag = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;

        for (char& c: word) {
            if ((cur->next)[c] == nullptr) return false; 
            cur = (cur->next)[c];
        }
        if (cur->flag) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (char& c: prefix) {
            if ((cur->next)[c] == nullptr) return false;
            cur = (cur->next)[c];
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
