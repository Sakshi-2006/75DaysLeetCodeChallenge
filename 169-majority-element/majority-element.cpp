class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0,can=0;
        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                can=nums[i];
            }
            if(nums[i]==can){
                cnt++;
            }else{
                cnt--;
            }
        }
        // return nums[i];,
        return can;
    }
};