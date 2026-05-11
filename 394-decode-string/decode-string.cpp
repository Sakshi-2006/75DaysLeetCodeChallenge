class Solution {
public:
    string decodeString(string s) {

        stack<int> numStack;
        stack<string> strStack;

        string currStr = "";
        int num = 0;

        for (char c : s) {

            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            else if (c == '[') {
                numStack.push(num);
                strStack.push(currStr);

                num = 0;
                currStr = "";
            }

            else if (c == ']') {

                int repeat = numStack.top();
                numStack.pop();

                string prevStr = strStack.top();
                strStack.pop();

                string temp = "";

                for (int i = 0; i < repeat; i++) {
                    temp += currStr;
                }

                currStr = prevStr + temp;
            }

            else {
                currStr += c;
            }
        }

        return currStr;
    }
};