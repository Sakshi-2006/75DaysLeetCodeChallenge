class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        if(words[startIndex] == target) return 0;

        int left = (startIndex - 1 + n) % n;
        int right = (startIndex + 1) % n;
        int dist = 1;

        while(left != startIndex && right != startIndex) {
            if(words[left] == target) return dist;
            else if(words[right] == target) return dist;
            left = (left - 1 + n) % n;
            right = (right + 1) % n;
            dist++;
        }

        return -1;
    }
};