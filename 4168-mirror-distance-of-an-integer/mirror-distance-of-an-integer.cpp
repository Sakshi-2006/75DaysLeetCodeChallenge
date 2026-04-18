class Solution {
public:
    int mirrorDistance(int n) {
        int rev = 0, dif = 0, orig = n;
        while (n) {
            int digit = n % 10;
            rev = rev * 10 + digit;
            n = n / 10;
        }
        dif = abs(rev) - abs(orig);
        return abs(dif);
    }
};