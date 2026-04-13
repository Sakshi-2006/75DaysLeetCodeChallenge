class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int l=0,r=nums.size()-1;
        int ans=INT_MAX;
        while(l<=r){
            if(nums[l]==target)ans=min(ans,abs(l-start));
            if(nums[r]==target)ans=min(ans,abs(r-start));
            l++;
            r--;
        
    }
    return ans;
    }
};