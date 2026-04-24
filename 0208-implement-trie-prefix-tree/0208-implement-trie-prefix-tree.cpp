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

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (node->children[index] == NULL) {
                node->children[index] = new TrieNode();
            }

            node = node->children[index];
        }

        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (node->children[index] == NULL) {
                return false;
            }

            node = node->children[index];
        }

        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;

        for (char ch : prefix) {
            int index = ch - 'a';

            if (node->children[index] == NULL) {
                return false;
            }

            node = node->children[index];
        }

        return true;
    }
};