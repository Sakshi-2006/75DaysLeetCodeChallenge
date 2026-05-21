class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;

        for(int num : arr1) {
            while(num > 0) {
                st.insert(num);
                num /= 10;
            }
        }
        int ans = 0;

        for(int num : arr2) {
            int x = num;
            int len = to_string(num).size();

            while(x > 0) {
                if(st.count(x)) {
                    ans = max(ans, len);
                    break;
                }
                x /= 10;
                len--;
            }
        }
        return ans;
    }
};