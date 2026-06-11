class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int count = 0;

        while (n) {
            n = n & (n - 1); // remove rightmost set bit
            count++;
        }

        return count;
    }
};