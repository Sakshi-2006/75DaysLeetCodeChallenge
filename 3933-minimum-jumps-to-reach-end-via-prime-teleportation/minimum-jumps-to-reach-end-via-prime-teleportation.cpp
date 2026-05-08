class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return 0;

        int MAXV = *max_element(nums.begin(), nums.end());

        // Smallest Prime Factor sieve
        vector<int> spf(MAXV + 1);

        for (int i = 0; i <= MAXV; i++)
            spf[i] = i;

        for (int i = 2; i * i <= MAXV; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= MAXV; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }

        auto isPrime = [&](int x) {
            return x > 1 && spf[x] == x;
        };

        // Map prime factor -> indices divisible by it
        unordered_map<int, vector<int>> divMap;

        for (int idx = 0; idx < n; idx++) {
            int x = nums[idx];
            set<int> factors;

            while (x > 1) {
                int p = spf[x];
                factors.insert(p);

                while (x % p == 0) {
                    x /= p;
                }
            }

            for (int p : factors) {
                divMap[p].push_back(idx);
            }
        }

        queue<pair<int, int>> q; // {index, steps}
        q.push({0, 0});

        vector<bool> visited(n, false);
        visited[0] = true;

        unordered_set<int> usedPrime;

        while (!q.empty()) {
            auto [i, steps] = q.front();
            q.pop();

            if (i == n - 1)
                return steps;

            // Adjacent moves
            vector<int> nextIndices = {i - 1, i + 1};

            for (int ni : nextIndices) {
                if (ni >= 0 && ni < n && !visited[ni]) {
                    visited[ni] = true;
                    q.push({ni, steps + 1});
                }
            }

            // Prime teleport
            int val = nums[i];

            if (isPrime(val) && usedPrime.find(val) == usedPrime.end()) {
                for (int ni : divMap[val]) {
                    if (!visited[ni]) {
                        visited[ni] = true;
                        q.push({ni, steps + 1});
                    }
                }

                usedPrime.insert(val);
            }
        }

        return -1;
    }
};