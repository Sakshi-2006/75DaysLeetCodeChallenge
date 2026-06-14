class Solution {
public:
// Take last bit of n
// ↓
// Append it to ans
// ↓
// Remove it from n
// ↓
// Repeat 32 times
    int reverseBits(int n) {
        unsigned int ans=0;//n = 1101 ans = 0000
        for(int i=0;i<32;i++){
            ans=(ans<<1);      //Shift answer left by 1 position. make space for next bit 0101 -> 1010
            // Iteration 1             2nd
                // n & 1 = 1             n & 1 = 0
                // Last bit is 1.        ans <<= 1
                // ans = ans << 1        0001 -> 0010
                //ans = 0000
                ans|=(n&1);        // Extract the last bit of n and put it into ans n = 1101 n & 1 = 1 Then: 1010 | 1 = 1011
                // ans |= 1             ans |= 1
                // ans = 0001           ans = 0010
            n>>=1;           // move to next bit Remove the bit we just processed.
                // Now:                 
                // n >>= 1              n >>= 1
                // n = 0110             0110 -> 0011
        }
        return ans;
    }
};