class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefMax(n), suffMin(n), ans(n);

        prefMax[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefMax[i] = max(prefMax[i - 1], nums[i]);
        }

        suffMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffMin[i] = min(suffMin[i + 1], nums[i]);
        }

        int start = 0;
        int segmentMax = nums[0];

        for (int i = 0; i < n; i++) {
            segmentMax = max(segmentMax, nums[i]);

            bool cut = (i == n - 1 || prefMax[i] <= suffMin[i + 1]);

            if (cut) {
                for (int j = start; j <= i; j++) {
                    ans[j] = segmentMax;
                }

                start = i + 1;

                if (start < n)
                    segmentMax = nums[start];
            }
        }

        return ans;
    }
};