class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i <= n; i++) {//n=3 
            bool flag = false;
            for (int j = 0; j < n; j++) {//j=2
                if (nums[j] == i) {//no 
                    flag = true;
                    break;
                }
            }
            if (!flag)//1
                return i;
        }
        return -1;
    }
};