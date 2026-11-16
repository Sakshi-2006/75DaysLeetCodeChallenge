class Solution {
public:
    string digitSum(string s, int k) {
        while (s.length() > k) { //only if length > k
            string ans = "";
            for (int i = 0; i < s.length(); i += k) { //divide
                int sum = 0;
                for (int j = i; j < i + k && j < s.length(); j++) {
                    sum = sum + s[j] - '0'; //sum
                }
                ans = ans + to_string(sum); //merge
            }
            s = ans;
        }
        return s;
    }
};