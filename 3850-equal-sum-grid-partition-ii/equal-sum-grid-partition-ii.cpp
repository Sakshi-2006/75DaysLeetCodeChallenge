class Solution {
public:
    vector<vector<int>> rotation(const vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> tmp(cols, vector<int>(rows));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                tmp[j][rows - 1 - i] = grid[i][j];
            }
        }
        return tmp;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long total = 0;
        int rows = grid.size();
        if (rows == 0) 
            return false;
        int cols = grid[0].size();

        for (const auto& row : grid) {
            for (int val : row) {
                total += val;
            }
        }

        for (int r = 0; r < 4; r++) {
            unordered_set<long long> visited;
            visited.insert(0);
            long long vals = 0;
            rows = grid.size();
            cols = grid[0].size();
            if (rows < 2) {
                grid = rotation(grid);
                continue;
            }
            if (cols == 1) {
                for (int i = 0; i < rows - 1; ++i) {
                    vals += grid[i][0];
                    long long flag = vals * 2 - total;
                    if (flag == 0 || flag == grid[0][0] || flag == grid[i][0]) {
                        return true;
                    }
                }
            } else {
                for (int i = 0; i < rows - 1; ++i) {
                    for (int j = 0; j < cols; ++j) {
                        visited.insert(grid[i][j]);
                        vals += grid[i][j];
                    }
                    
                    long long flag = vals * 2 - total;

                    if (i == 0) {
                        if (flag == 0 || flag == grid[0][0] || flag == grid[0][cols - 1]) {
                            return true;
                        }
                    } else {
                        if (visited.find(flag) != visited.end()) {
                            return true;
                        }
                    }
                }
            }
            grid = rotation(grid);
        }

        return false;
    }
};