class Solution {
public:
    long long dp[101][101];

    long long solve(int i, int j, vector<int>& robots, vector<vector<int>>& factories) {
        if (i == robots.size()) return 0;
        if (j == factories.size()) return 1e15;

        if (dp[i][j] != -1) return dp[i][j];

        long long res = solve(i, j + 1, robots, factories); // skip factory

        long long dist = 0;
        for (int k = 0; k < factories[j][1] && i + k < robots.size(); k++) {
            dist += abs(robots[i + k] - factories[j][0]);
            res = min(res, dist + solve(i + k + 1, j + 1, robots, factories));
        }

        return dp[i][j] = res;
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, robot, factory);
    }
};