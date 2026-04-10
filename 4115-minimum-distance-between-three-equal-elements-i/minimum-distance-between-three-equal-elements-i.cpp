class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> vec(n);
        for(int i = 0; i < n; i++) vec[i] = {nums[i], i};

        sort(vec.begin(), vec.end());

        int mini = INT_MAX;

        for(int i = 1; i < n-1; i++) {
            auto prev = vec[i-1];
            auto curr = vec[i];
            auto next = vec[i+1];

            if(prev.first == curr.first && curr.first == next.first) {
                int dist = 0;
                dist += abs(prev.second - curr.second);
                dist += abs(curr.second - next.second);
                dist += abs(next.second - prev.second);

                mini = min(mini, dist);
            }
        }

        if(mini == INT_MAX) return -1;
        return mini;
    }
};