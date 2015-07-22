class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() : _is_word(false) {
        memset(_nodes, NULL, 26 * sizeof(TrieNode *));
    }
    
    bool _is_word;
    TrieNode *_nodes[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Inserts a word into the trie.
    void insert(string word) {
        if(word.empty())
        {
            return;
        }
        
        TrieNode *cur = root;
        for(std::string::const_iterator cit = word.begin(); cit != word.end(); cit++)
        {
            int idx = *cit - 'a';
            if(!cur->_nodes[idx])
            {
                cur->_nodes[idx] = new TrieNode();
            }
            cur = cur->_nodes[idx];
        }
        cur->_is_word = true;
    }
    
    // Returns if the word is in the trie.
    bool search(string word) {
        if(word.empty())
        {
            return false;
        }
        
        TrieNode *cur = root;
        for(std::string::const_iterator cit = word.begin(); cit != word.end(); cit++)
        {
            int idx = *cit - 'a';
            if(!cur->_nodes[idx])
            {
                return false;
            }
            cur = cur->_nodes[idx];
        }
        return cur->_is_word;
    }
    
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        if(prefix.empty())
        {
            return false;
        }
        
        TrieNode *cur = root;
        for(std::string::const_iterator cit = prefix.begin(); cit != prefix.end(); cit++)
        {
            int idx = *cit - 'a';
            if(!cur->_nodes[idx])
            {
                return false;
            }
            cur = cur->_nodes[idx];
        }
        return true;
    }
    
private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");