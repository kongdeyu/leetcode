struct TrieNode {
    TrieNode() : _nodes(26, NULL), _is_word(false) {}
    
    std::vector<TrieNode *> _nodes;
    bool _is_word;
};

class WordDictionary {
public:
    WordDictionary() : _root(new TrieNode()) {}
    
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *cur = _root;
        for(std::string::const_iterator cit = word.begin(); cit != word.end(); cit++)
        {
            int idx = *cit - 'a';
            if(cur->_nodes[idx] == NULL)
            {
                cur->_nodes[idx] = new TrieNode();
            }
            cur = cur->_nodes[idx];
        }
        cur->_is_word = true;
    }
    
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        if(word.empty() || _root == NULL)
        {
            return false;
        }
        return search(word, 0, _root);
    }
    
private:
    bool search(const string &word, int idx, TrieNode *root) {
        if(idx == word.size())
        {
            return root->_is_word;
        }
        
        if(word[idx] == '.')
        {
            for(std::vector<TrieNode *>::const_iterator cit = root->_nodes.begin(); cit != root->_nodes.end(); cit++)
            {
                if(*cit != NULL && search(word, idx + 1, *cit))
                {
                    return true;
                }
            }
            return false;
        }
        else
        {
            return (root->_nodes)[word[idx] - 'a'] != NULL && search(word, idx + 1, (root->_nodes)[word[idx] - 'a']);
        }
    }
    
    TrieNode *_root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");