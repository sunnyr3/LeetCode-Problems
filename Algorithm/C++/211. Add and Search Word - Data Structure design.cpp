class Trie {
public:
    bool isCompleted;
    vector<Trie*> child;
    Trie(): isCompleted(false), child(vector<Trie*>(26, nullptr)) {}
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Trie();
    }
    
    ~WordDictionary() {
        delete root;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Trie *curr = root;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (!curr->child[index])
                curr->child[index] = new Trie();
            curr = curr->child[index];
        }
        curr->isCompleted = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word.c_str(), root);
    }
    
private:
    Trie *root;
    
    bool search(const char *c, Trie *curr) {
        if (!curr) return false;
        if (*c == '\0') return curr->isCompleted;
        if (*c != '.')
            return search(c+1, curr->child[*c - 'a']);
        else {
            for (int i = 0; i < 26; i++) {
                if (search(c+1, curr->child[i]))
                    return true;
            }
            return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */