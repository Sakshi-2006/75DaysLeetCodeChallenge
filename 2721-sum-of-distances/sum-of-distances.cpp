class Solution {
public:
    // eg, 2 1 1 2 1 1 2 1 
    // For index = 4 
    // left: (4 - 1) + ( 4 - 2) --> (4 * 2) + (1 + 2)
    // right: (5 - 4) + (7 - 4) --> (5 + 7) - (4 * 2)

    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) mp[nums[i]].push_back(i);

        vector<long long> ans(n, 0);

        for(auto &it : mp) {
            vector<int> &curr = it.second; // writing '&' avoids un-necessary copy of the array
            int sz = curr.size();
            if(sz == 1) continue;

            // prefix sum of indices
            vector<long long> prefix(sz);
            prefix[0] = curr[0];
            for(int j = 1; j < sz; j++) prefix[j] = prefix[j-1] + curr[j];

            // compute answer for each index in the curr array
            for(int pos = 0; pos < sz; pos++) {
                int index = curr[pos]; 
                long long left = 0, right = 0;

                if(pos > 0) left += (1LL * pos * index) - prefix[pos - 1];
                if(pos < sz-1) right += (prefix[sz - 1] - prefix[pos]) - (1LL * (sz - 1 - pos) * index);
                ans[index] = left + right;
            }
        }

        return ans;
    }
};