class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        vector<pair<int, pair<int,int>>> vec(n); // {position, {health_signed, original_index}}
        for(int i = 0; i < n; i++) {
            if(directions[i] == 'R') vec[i] = {positions[i], {healths[i], i}};
            else vec[i] = {positions[i], {-healths[i], i}};
        }
        
        sort(vec.begin(), vec.end());

        stack<pair<int,int>> st; // {health_signed, original_index}

        for(int i = 0; i < n; i++) {
            int ele = vec[i].second.first;
            int idx = vec[i].second.second;

            if(st.empty()) { 
                st.push({ele, idx}); 
                continue;
            }

            if(ele > 0 && st.top().first > 0) st.push({ele, idx});
            else if(st.top().first < 0) st.push({ele, idx}); 
            else if(ele < 0 && st.top().first > 0) {
                if(st.top().first > abs(ele)) { // smaller one will explode and greater will decrease by 1
                    auto [robo, index] = st.top();
                    st.pop();
                    st.push({robo - 1, index}); 
                }
                else if(st.top().first == abs(ele)) st.pop(); // both will explode
                else {
                    while(!st.empty() && st.top().first < abs(ele) && st.top().first > 0) { // keep removing the smaller ones
                        st.pop();
                        ele++; // keep decreasing the health of current robot by 1 with each collision (ele is -ve)
                    }
                    if(st.empty() || st.top().first < 0) st.push({ele, idx});
                    else if(st.top().first == abs(ele)) st.pop();
                    else { // current robot destroyed
                        auto [robo, index] = st.top();
                        st.pop();
                        st.push({robo - 1, index});
                    }
                }
            }
        }

        vector<int> ans(n, -1);
        while(!st.empty()) {
            auto [val, idx] = st.top(); 
            st.pop();
            ans[idx] = abs(val);
        }

        vector<int> result;
        for(int i = 0; i < n; i++)
            if(ans[i] != -1) result.push_back(ans[i]);

        return result;
    }
};