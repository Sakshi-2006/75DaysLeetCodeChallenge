class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        string digits = "123456789";
        vector<int> ans;

        int lowLen = to_string(low).size();
        int highLen = to_string(high).size();

        for (int len = lowLen; len <= highLen; len++) {

            for (int i = 0; i + len <= 9; i++) {

                int num = stoi(digits.substr(i, len));

                if (num >= low && num <= high)
                    ans.push_back(num);
            }
        }

        return ans;
    }
};