class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int ans=0;
        int mod=1e9+7;

        for(auto &x:queries){
            int l=x[0], r=x[1], k=x[2], v=x[3];

            while(l<=r){
                nums[l]=(1LL*nums[l]*v)%mod;
                l+=k;
            }
        }

        for(auto &x:nums)ans^=x;

        return ans;
    }
};