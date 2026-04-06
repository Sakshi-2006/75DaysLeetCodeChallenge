class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> obstacleSet;
        
        for (auto &obs : obstacles) {
            obstacleSet.insert(to_string(obs[0]) + "," + to_string(obs[1]));
        }

        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};

        int dir = 0;
        int x = 0, y = 0;
        int maxDistance = 0;

        for (int command : commands) {
            if (command == -1) {
                dir = (dir + 1) % 4;
            }
            else if (command == -2) {
                dir = (dir + 3) % 4;
            }
            else {
                for (int step = 0; step < command; step++) {
                    int nextX = x + dx[dir];
                    int nextY = y + dy[dir];

                    string nextPos = to_string(nextX) + "," + to_string(nextY);

                    if (obstacleSet.count(nextPos)) {
                        break;
                    }

                    x = nextX;
                    y = nextY;

                    maxDistance = max(maxDistance, x * x + y * y);
                }
            }
        }

        return maxDistance;
    }
};