class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;

        for (int i = 0; i < nums.size(); i++) {
            bool flag = false;
            for (int j = 0; j < i; j++) {
                if (nums[i] == nums[j]) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                nums[k++] = nums[i];
            }
        }

        return k;
    }
};