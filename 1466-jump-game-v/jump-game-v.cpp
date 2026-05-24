class Solution {
public:
    int dp[1001];

    int solveMem(vector<int>& arr, int d, int i) {
        int n = arr.size();

        if(dp[i] != -1)
            return dp[i];

        int ans = 1;

        // move right
        for(int j = i + 1; j <= min(i + d, n - 1); j++) {
            if(arr[j] >= arr[i]) break;
            ans = max(ans, 1 + solveMem(arr, d, j));
        }

        // move left
        for(int j = i - 1; j >= max(0, i - d); j--) {
            if(arr[j] >= arr[i]) break;
            ans = max(ans, 1 + solveMem(arr, d, j));
        }

        return dp[i] = ans;
    }

    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        int ans = 1;

        memset(dp, -1, sizeof(dp));

        for(int i = 0; i < n; i++) {
            ans = max(ans, solveMem(arr, d, i));
        }

        return ans;
    }
};