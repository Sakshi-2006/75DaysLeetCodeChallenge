class Solution {
public:
    int reverse_num(int x) {
        int rev = 0;
        while(x > 0) {
            int digit = x % 10;
            rev = rev * 10 + digit;
            x = x / 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp; // element --> index
        int ans = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            int rev = reverse_num(nums[i]);
            cout << rev << " ";
            if(mp.count(nums[i])) ans = min(ans, i - mp[nums[i]]);
            mp[rev] = i;
        }

        if(ans == INT_MAX) return -1;
        return ans;
    }
};