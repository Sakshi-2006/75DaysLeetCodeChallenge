// lc 3736 C++ Code

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_value = *max_element(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return max_value * nums.size() - sum;
    }
};