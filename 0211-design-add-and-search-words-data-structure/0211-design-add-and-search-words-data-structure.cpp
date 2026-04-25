class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isEnd = false;
    }
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;

        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }

        node->isEnd = true;
    }

    bool searchHelper(string& word, int i, TrieNode* node) {
        if (!node) return false;

        if (i == word.size()) {
            return node->isEnd;
        }

        if (word[i] == '.') {
            for (int j = 0; j < 26; j++) {
                if (node->children[j] && 
                    searchHelper(word, i + 1, node->children[j])) {
                    return true;
                }
            }
            return false;
        } else {
            int idx = word[i] - 'a';
            return searchHelper(word, i + 1, node->children[idx]);
        }
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};