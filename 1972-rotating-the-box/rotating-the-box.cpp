class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {

        int n = boxGrid.size();
        int m = boxGrid[0].size();

        vector<vector<char>> result(m, vector<char>(n));

        // rotate clockwise
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                result[j][n - 1 - i] = boxGrid[i][j];
            }
        }

        // gravity
        for(int j = 0; j < n; j++) {

            int spaceBottom = m - 1;

            for(int i = m - 1; i >= 0; i--) {

                if(result[i][j] == '*') {
                    spaceBottom = i - 1;
                }

                else if(result[i][j] == '#') {

                    result[i][j] = '.';
                    result[spaceBottom][j] = '#';

                    spaceBottom--;
                }
            }
        }

        return result;
    }
};