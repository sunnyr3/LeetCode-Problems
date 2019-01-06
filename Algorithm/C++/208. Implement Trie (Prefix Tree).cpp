class TrieNode {
public:
    bool isCompleted;
    vector<TrieNode*> children;
    TrieNode(): isCompleted(false), children(vector<TrieNode*>(26, NULL)) {}
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *curr = root;
        for (char c: word) {
            if (!curr->children[c - 'a']) {
                curr->children[c - 'a'] = new TrieNode();
            }
            curr = curr->children[c - 'a'];
        }
        curr->isCompleted = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *curr = root;
        for (char c : word) {
            if (!curr) return false;
            curr = curr->children[c - 'a'];
        }
        
        if (!curr || !curr->isCompleted) return false;
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        for (char c : prefix) {
            if (!curr) return false;
            curr = curr->children[c - 'a'];
        }
        return curr != NULL;
    }

private:
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */