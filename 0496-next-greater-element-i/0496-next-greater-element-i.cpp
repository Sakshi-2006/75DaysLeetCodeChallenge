class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int> st;
        unordered_map<int, int> mp;

        // process nums2
        for (int num : nums2) {

            while (!st.empty() && num > st.top()) {
                mp[st.top()] = num;
                st.pop();
            }

            st.push(num);
        }

        // remaining elements have no greater element
        while (!st.empty()) {
            mp[st.top()] = -1;
            st.pop();
        }

        vector<int> ans;

        // answer for nums1
        for (int num : nums1) {
            ans.push_back(mp[num]);
        }

        return ans;
    }
};