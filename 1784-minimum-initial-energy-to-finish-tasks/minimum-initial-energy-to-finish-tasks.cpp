class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {

        // sort by (minimum - actual) descending
        sort(tasks.begin(), tasks.end(),
             [](vector<int>& a, vector<int>& b) {
                 return (a[1] - a[0]) > (b[1] - b[0]);
             });

        int energy = 0;
        int current = 0;

        for (auto& task : tasks) {

            int actual = task[0];
            int minimum = task[1];

            // if current energy insufficient
            if (current < minimum) {
                energy += (minimum - current);
                current = minimum;
            }

            // perform task
            current -= actual;
        }

        return energy;
    }
};