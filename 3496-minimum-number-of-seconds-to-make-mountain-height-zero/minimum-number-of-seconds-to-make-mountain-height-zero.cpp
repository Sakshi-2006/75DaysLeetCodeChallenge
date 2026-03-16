class Solution {
public:
    int find_height_x(long long t, long long T) {
        long long val = (8 * T) / t;
        long long x = (-1 + sqrt(1 + val)) / 2;
        return x;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int n = workerTimes.size();

        long long low = 0, high = 1e18;
        long long ans = 1e18;

        while(low <= high) {
            long long mid = low + (high - low) / 2;

            long long total_height = 0;
            for(auto t : workerTimes) {
                total_height += find_height_x(t, mid);
                if(total_height >= mountainHeight) break;
            }

            if(total_height >= mountainHeight) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return ans;
    }
};