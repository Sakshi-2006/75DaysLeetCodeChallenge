class Solution {
public:
    //  4 0 2 0
    //  0 3 0 1
    //  2 0 2 0 
    //  0 1 0 1
    // this matrix is symmetric always (also, see the pattern of diagonal elements)
    // hme prefix ki length de rakhi  haii (len), we need to go till i se len and j se len
    // verify isiliye kr rhe hn kyuki, we are not considering lcp[i][j] = 0 wale cells,
    // so, it is possible ki hmare generated string me vo non-zero bn jaye

    vector<int> parent;

    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        int ux = find(x);
        int uy = find(y);
        if(ux == uy) return;
        parent[ux] = uy;
    }

    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        
        // check for symmetric matrix
        for(int i = 0; i < n; i++) {
            if(lcp[i][i] != n-i) return "";
            for(int j = 0; j < n; j++) {
                if(lcp[i][j] != lcp[j][i]) return "";
            }
        }

        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        string word(n, ' ');

        // merge positions
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) { // dealing with upper triangle is enough
                if(lcp[i][j] > 0) unite(i, j);
            }
        }

        // start assigning characters to each connected component 
        char ch = 'a';
        unordered_map<int, char> mp;

        for(int i = 0; i < n; i++) {
            int root = find(i);
            if(!mp.count(root)) {
                if(ch > 'z') return "";
                mp[root] = ch++;
            }
            word[i] = mp[root];
        }

        // verify lcp by creating a lcp of our created string "word" and comparing to given lcp
        vector<vector<int>> actual(n + 1, vector<int>(n + 1, 0));

        for(int j = n-1; j >= 0; j--) {
            for(int i = n-1; i >= 0; i--) {
                if(word[i] == word[j]) actual[i][j] = 1 + actual[i+1][j+1];
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j =  0; j < n; j++) {
                if(actual[i][j] != lcp[i][j]) return "";
            }
        }

        return word;
    }
};