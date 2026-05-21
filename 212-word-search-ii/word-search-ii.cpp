class TrieNode {
public:
    TrieNode* children[26];
    string word;

    TrieNode() {
        word = "";

        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Solution {
public:

    vector<string> ans;

    void insert(string word, TrieNode* root) {

        TrieNode* node = root;

        for (char c : word) {

            int idx = c - 'a';

            if (node->children[idx] == NULL) {
                node->children[idx] = new TrieNode();
            }

            node = node->children[idx];
        }

        node->word = word;
    }

    void dfs(vector<vector<char>>& board,
             int i,
             int j,
             TrieNode* node) {

        char c = board[i][j];

        if (c == '#' || node->children[c - 'a'] == NULL)
            return;

        node = node->children[c - 'a'];

        // word found
        if (node->word != "") {
            ans.push_back(node->word);

            // avoid duplicates
            node->word = "";
        }

        board[i][j] = '#';

        int dirs[4][2] = {
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };

        for (auto& d : dirs) {

            int ni = i + d[0];
            int nj = j + d[1];

            if (ni >= 0 &&
                nj >= 0 &&
                ni < board.size() &&
                nj < board[0].size()) {

                dfs(board, ni, nj, node);
            }
        }

        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        TrieNode* root = new TrieNode();

        // build trie
        for (string word : words) {
            insert(word, root);
        }

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                dfs(board, i, j, root);
            }
        }

        return ans;
    }
};