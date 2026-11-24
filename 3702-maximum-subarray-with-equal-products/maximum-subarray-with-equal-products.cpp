class Solution {
public:
    int maxLength(vector<int>& nums) { //outer loop
        int ans = 0, n = nums.size();

        for(int i = 0; i < n; i++) {
            long long prod = 1;
            int g = 0, l = 1;

            for(int j = i; j < n; j++) { // inner loop
                if(prod > 25200 / nums[j]) break;

                prod *= nums[j];
                g = gcd(g, nums[j]);
                l = lcm(l, nums[j]);

                if(prod == 1LL * g * l)
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};