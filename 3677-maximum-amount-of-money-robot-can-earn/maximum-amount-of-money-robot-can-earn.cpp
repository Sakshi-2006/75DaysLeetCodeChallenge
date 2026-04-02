class Solution {
public:
    // note that in this question, -1 can be a valid answer, so we can't assign our dp matrix by -1
    // dp[i][j][k] = Maximum coins we can earn starting from cell (i, j) if we still have k neutralizations left.
    vector<vector<vector<int>>> dp;
    int n, m;

    int solve(int i, int j, int k, vector<vector<int>> &coins) {
        if(i >= n || j >= m) return -1e9;
        if(i == n-1 && j == m-1) {
            if(coins[i][j] > 0) return coins[i][j];
            else {
                if(k > 0) return 0;
                else return coins[i][j];
            }
        }

        if(dp[i][j][k] != -1e9) return dp[i][j][k]; // -1 can be a valid answer

        int val = coins[i][j];
        int right = -1e9, down = -1e9;

        if(val >= 0) {
            right = val + solve(i, j + 1, k, coins);
            down = val + solve(i + 1, j, k, coins);
        }
        else {
            // take loss
            int right_loss = val + solve(i, j + 1, k, coins); // val is already -ve, no need to add -ve sign
            int down_loss = val + solve(i + 1, j, k, coins);

            // use neutralization
            int right_neutralized = -1e9;
            int down_neutralized = -1e9;
            if(k > 0) {
                right_neutralized = 0 + solve(i, j + 1, k - 1, coins);
                down_neutralized = 0 + solve(i + 1, j, k - 1, coins);
            }

            // take max of both
            right = max(right_loss, right_neutralized);
            down = max(down_loss, down_neutralized);
        }

        return dp[i][j][k] = max(right, down);
    }


    int maximumAmount(vector<vector<int>>& coins) {
        n = coins.size();
        m = coins[0].size();

        dp.resize(n, vector<vector<int>>(m, vector<int>(3, -1e9)));
        return solve(0, 0, 2, coins); // we have 2 neutralizations initially
    }
};