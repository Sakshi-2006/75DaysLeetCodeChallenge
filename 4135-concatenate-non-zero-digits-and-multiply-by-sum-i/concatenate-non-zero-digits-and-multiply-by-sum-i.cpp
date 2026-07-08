class Solution {
public:
    long long sumAndMultiply(int n) {

        long long x = 0;
        long long sum = 0;

        if (n == 0)
            return 0;

        vector<int> digits;

        while (n > 0) {
            int digit = n % 10;
            if (digit != 0)
                digits.push_back(digit);
            n /= 10;
        }

        reverse(digits.begin(), digits.end());

        for (int digit : digits) {
            x = x * 10 + digit;
            sum += digit;
        }

        return x * sum;
    }
};