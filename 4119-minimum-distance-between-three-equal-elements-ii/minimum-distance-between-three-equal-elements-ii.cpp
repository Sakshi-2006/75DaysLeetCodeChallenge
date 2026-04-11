class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int ans = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]].push_back(i);
            if(mp[nums[i]].size() >= 3){
                int k = mp[nums[i]].size();
                ans = min(ans, 2 * (i - mp[nums[i]][k-3]));
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
