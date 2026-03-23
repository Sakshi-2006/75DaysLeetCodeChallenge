class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<pair<long long, long long>>> dp; // {max, min}
    vector<vector<int>> vis;

    pair<long long, long long> solve(int i, int j, vector<vector<int>> &grid) {
        if(i < 0 || j < 0) return {LLONG_MIN, LLONG_MAX};
        if(i == 0 && j == 0) return {grid[i][j], grid[i][j]};
        if(vis[i][j]) return dp[i][j];

        long long maxi = LLONG_MIN;
        long long mini = LLONG_MAX;

        auto up = solve(i - 1, j, grid);
        auto left = solve(i, j - 1, grid);

        vector<pair<long long, long long>> prev = {up, left};
        int curr = grid[i][j];

        for(auto &it : prev) {
            if(it.first == LLONG_MIN || it.second == LLONG_MAX) continue;

            long long a = curr * 1LL *  it.first;
            long long b = 1LL * curr * it.second;

            maxi = max({maxi, a, b});
            mini = min({mini, a, b});
        }

        cout << maxi << " " << mini << endl;
        vis[i][j] = 1;
        return dp[i][j] = {maxi, mini};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        
        dp.resize(n, vector<pair<long long, long long>>(m));
        vis.resize(n, vector<int>(m, 0));
        auto ans = solve(n-1, m-1, grid);

        if(ans.first < 0) return -1; // {maxi, mini}
        return ans.first % MOD;
    }
};