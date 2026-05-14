class Solution {
public:

    bool canEat(vector<int>& piles, int h, int speed) {

        long long hours = 0;

        for (int bananas : piles) {

            // ceil(bananas / speed)
            hours += (bananas + speed - 1) / speed;
        }

        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        int ans = right;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (canEat(piles, h, mid)) {
                ans = mid;
                right = mid - 1; // try smaller speed
            }
            else {
                left = mid + 1;
            }
        }

        return ans;
    }
};