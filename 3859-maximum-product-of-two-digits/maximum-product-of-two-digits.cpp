class Solution {
public:
    int maxProduct(int n) {
        int d1, d2, maxProd = 0;

        while (n > 9) { // at least 2 digits
            d1 = n % 10;
            int temp = n / 10;

            while (temp > 0) {
                d2 = temp % 10;
                maxProd = max(maxProd, d1 * d2);
                temp /= 10;
            }

            n /= 10;
        }

        return maxProd;
    }
};