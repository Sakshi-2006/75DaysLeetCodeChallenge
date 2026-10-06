class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0 ;
        stack<char>st;
       
        for(char c : s){
            if(c == '(') {
                st.push('('); count++;
            }
            else{
                if(!st.empty() && st.top() == '('){
                    st.pop(); count--;
                }
                else {
                    st.push(')');
                    count++;
                }
            }
            
        }
       
        return count;
    }
};