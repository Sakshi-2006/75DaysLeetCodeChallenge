class Solution {
public:
    int minJumps(std::vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;

        // Map each value to list of indices
        std::unordered_map<int, std::vector<int>> valToIndices;
        for (int i = 0; i < n; ++i) {
            valToIndices[arr[i]].push_back(i);
        }

        std::vector<int> dist(n, -1);
        dist[0] = 0;
        std::queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int idx = q.front();
            q.pop();

            if (idx == n - 1) return dist[idx];

            // Jump to idx+1
            if (idx + 1 < n && dist[idx + 1] == -1) {
                dist[idx + 1] = dist[idx] + 1;
                q.push(idx + 1);
            }
            // Jump to idx-1 (only if >0)
            if (idx - 1 > 0 && dist[idx - 1] == -1) {
                dist[idx - 1] = dist[idx] + 1;
                q.push(idx - 1);
            }

            // Jump to all indices with same value
            if (valToIndices.count(arr[idx])) {
                for (int j : valToIndices[arr[idx]]) {
                    if (dist[j] == -1) {
                        dist[j] = dist[idx] + 1;
                        q.push(j);
                    }
                }
                valToIndices[arr[idx]].clear(); // Avoid reprocessing
            }
        }
        return -1;
    }
};