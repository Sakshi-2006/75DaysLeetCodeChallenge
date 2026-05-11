class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {

        vector<int> ans;

        for (int num : nums) {

            vector<int> digits;

            // extract digits
            while (num > 0) {
                digits.push_back(num % 10);
                num /= 10;
            }

            // reverse to maintain order
            reverse(digits.begin(), digits.end());

            // add to answer
            for (int d : digits) {
                ans.push_back(d);
            }
        }

        return ans;
    }
};