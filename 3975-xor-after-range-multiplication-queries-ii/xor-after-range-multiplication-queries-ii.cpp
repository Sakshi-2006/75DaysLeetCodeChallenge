class Solution {
public:
    const int MOD = 1e9 + 7;

    // concept of binary exponentiation --> for fermat's little theorem, pow(v, MOD - 2)
    // that is, (a / b) % MOD = a * ((1 / b) % MOD) =  a * pow(b, MOD - 2) 
    long long power(long long a, long long b) {
        if(b == 0) return 1;

        long long half = power(a, b/2);
        long long ans = (half * half) % MOD;

        if(b % 2 != 0) ans = (ans * a) % MOD;
        return ans;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int block_size = ceil(sqrt(n));

        unordered_map<int, vector<vector<int>>> mp;

        for(auto &query : queries) {
            int l = query[0], r = query[1];
            int k = query[2], v = query[3];

            if(k >= block_size) { // simply apply brute force
                for(int i = l; i <= r; i = i + k) {
                    nums[i] = (1LL * nums[i] * v) % MOD;
                }
            }
            else { // k < block_size (multiple updates will happen, so need some optimization)
                // Difference array technique with jumps + square root decomposition
                mp[k].push_back(query);
            }
        }

        for(auto &[k, all_queries] : mp) {
            vector<long long> diff(n, 1);

            for(auto &query : all_queries) {
                int l = query[0], r = query[1];
                int k = query[2], v = query[3];

                diff[l] = (diff[l] * v) % MOD;
                int steps = (r - l) / k; // steps inside the range
                int next = l + (steps + 1) * k; // first steps outside the range
                if(next < n) diff[next] = (1LL * diff[next] * power(v, MOD - 2)) % MOD; // (diff[next] / v) % MOD 
            }

            // comulative product of diff array
            for(int i = 0; i < n; i++) {
                if(i - k >= 0) diff[i] = (diff[i] * diff[i - k]) % MOD;
            }

            // apply diff to nums
            for(int i = 0; i < n; i++) {
                nums[i] = (1LL * nums[i] * diff[i]) % MOD;
            }
        }

        int xorr = 0;
        for(int i = 0; i < n; i++) xorr = xorr ^ nums[i];

        return xorr;
    }
};