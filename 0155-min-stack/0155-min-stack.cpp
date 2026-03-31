#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> st, minSt;

    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        
        // Push min value
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }
    
    void pop() {
        if (st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};