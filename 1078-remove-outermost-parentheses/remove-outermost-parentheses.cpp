class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int count = 0;

        for (char c : s) {
            if (c == '(') {
                if (count > 0)
                    ans += c;//()(
                count++;//1 2 3
            } else {
                count--;//1
                if (count > 0)
                    ans += c;//()
            }
        }

        return ans;
    }
};