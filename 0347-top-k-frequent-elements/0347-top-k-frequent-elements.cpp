#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        vector<pair<int,int>> v;
        int count = 1;

        for(int i = 1; i < nums.size(); i++){

            if(nums[i] == nums[i-1]){
                count++;
            }
            else{
                v.push_back({count, nums[i-1]});
                count = 1;
            }
        }

        v.push_back({count, nums.back()});

        sort(v.begin(), v.end(), greater<pair<int,int>>());

        vector<int> ans;

        for(int i = 0; i < k; i++){
            ans.push_back(v[i].second);
        }

        return ans;
    }
};