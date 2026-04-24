class Solution {
public:
   int furthestDistanceFromOrigin(string moves) {
    int L = 0, R = 0, u_score = 0;
    for (char ch : moves) {
        if (ch == 'L') L++;
        else if (ch == 'R') R++;
        else u_score++;  // for '_'
    }
    return abs(R - L) + u_score;
}
};   