class Solution {
public:
    vector<vector<vector<int>>> dp;

    int get_dist(int pos1, int pos2) {
        auto [x1, y1] = get_coordinate(pos1);
        auto [x2, y2] = get_coordinate(pos2);

        return abs(x1 - x2) + abs(y1 - y2);
    }

    pair<int, int> get_coordinate(char ch) {
        int position = ch - 'A'; // example: for 'C', position = 2
        return {position / 6, position % 6}; // 6 is the number of columns
    }

    int solve(int index, int f1, int f2, string &word) {
        if(index == word.size()) return 0;
        if(dp[index][f1][f2] != -1) return dp[index][f1][f2];

        int curr = word[index] - 'A';

        // both fingers not used yet
        if(f1 == 26 && f2 == 26) { // use any of them
            return dp[index][f1][f2] = 0 + solve(index + 1, curr, f2, word); // let's use finger 1
        }

        // finger 2 not used before
        if(f2 == 26) {
            int move_f2 = 0 + solve(index + 1, f1, curr, word);
            int move_f1 = get_dist(f1, curr) + solve(index + 1, curr, f2, word); // again move finger 1

            return dp[index][f1][f2] = min(move_f1, move_f2);
        }

        // if both were used before
        int move_f1 = get_dist(f1, curr) + solve(index + 1, curr, f2, word); 
        int move_f2 = get_dist(f2, curr) + solve(index + 1, f1, curr, word); 

        return dp[index][f1][f2] = min(move_f1, move_f2);
    }

    int minimumDistance(string word) {
        int n = word.size();
        // finger1 = {x1, y1}
        // finger2 = {x2, y2}

        dp.assign(n, vector<vector<int>>(27, vector<int>(27, -1)));
        return solve(0, 26, 26, word); // initially, f1 and f2 are not pointing to any character
    }
};