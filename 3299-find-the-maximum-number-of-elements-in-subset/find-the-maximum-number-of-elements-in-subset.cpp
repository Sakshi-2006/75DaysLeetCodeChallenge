class Solution {
public:
    int maximumLength(vector<int>& nums) {

        unordered_map<long long, int> cnt;

        for (int x : nums)
            cnt[x]++;

        int ans = 1;

        // Handle value 1 separately
        if (cnt.count(1)) {
            ans = cnt[1];
            if (ans % 2 == 0)
                ans--;
        }

        for (auto &[num, _] : cnt) {

            if (num == 1)
                continue;

            long long x = num;
            int len = 0;

            while (cnt.count(x) && cnt[x] >= 2) {
                len += 2;
                x = x * x;
            }

            if (cnt.count(x))
                len++;
            else
                len--;

            ans = max(ans, len);
        }

        return ans;
    }
};