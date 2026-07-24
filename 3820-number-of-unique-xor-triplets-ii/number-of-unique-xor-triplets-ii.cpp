class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<int> values;
        vector<bool> present(1501, false);

        for (int x : nums) {
            if (!present[x]) {
                present[x] = true;
                values.push_back(x);
            }
        }

        vector<bool> dp(MAXX, false), ndp(MAXX, false);
        dp[0] = true;

        // Pick exactly 3 elements (repetition allowed)
        for (int cnt = 0; cnt < 3; cnt++) {
            fill(ndp.begin(), ndp.end(), false);

            for (int x = 0; x < MAXX; x++) {
                if (!dp[x]) continue;

                for (int v : values) {
                    ndp[x ^ v] = true;
                }
            }

            dp.swap(ndp);
        }

        int ans = 0;
        for (bool ok : dp)
            if (ok) ans++;

        return ans;
    }
};