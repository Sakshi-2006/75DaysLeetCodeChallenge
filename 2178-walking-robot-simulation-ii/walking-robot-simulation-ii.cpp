class Robot {
public:
    int w, h;
    int x, y;         // current position
    int dir;          // 0=East, 1=North, 2=West, 3=South

    Robot(int width, int height) {
        w = width;
        h = height;
        x = 0;
        y = 0;
        dir = 0; // East
    }
    
    void step(int num) {
        int perimeter = 2 * (w + h) - 4;
        num %= perimeter;

        // Special case: full cycle
        if (num == 0 && x == 0 && y == 0) {
            dir = 3; // South
            return;
        }

        while (num--) {
            if (dir == 0) { // East
                if (x + 1 < w) x++;
                else { dir = 1; y++; }
            }
            else if (dir == 1) { // North
                if (y + 1 < h) y++;
                else { dir = 2; x--; }
            }
            else if (dir == 2) { // West
                if (x - 1 >= 0) x--;
                else { dir = 3; y--; }
            }
            else { // South
                if (y - 1 >= 0) y--;
                else { dir = 0; x++; }
            }
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        if (dir == 0) return "East";
        if (dir == 1) return "North";
        if (dir == 2) return "West";
        return "South";
    }
};