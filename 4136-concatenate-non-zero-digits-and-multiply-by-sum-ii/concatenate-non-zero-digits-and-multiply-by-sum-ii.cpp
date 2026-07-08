class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        long long MOD = 1e9 + 7;
        int n = s.size();
        
        // 1-based prefix tracking arrays
        vector<int> nz_count(n + 1, 0);    
        vector<int> sum_digits(n + 1, 0);  
        vector<long long> pref_val(n + 1, 0); 
        
        // Precompute powers of 10 modulo MOD
        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }
        
        // Populate the prefix arrays
        for (int i = 0; i < n; ++i) {
            int digit = s[i] - '0';
            
            if (digit != 0) {
                nz_count[i + 1] = nz_count[i] + 1;
                sum_digits[i + 1] = sum_digits[i] + digit;
                pref_val[i + 1] = (pref_val[i] * 10 + digit) % MOD;
            } else {
                nz_count[i + 1] = nz_count[i];
                sum_digits[i + 1] = sum_digits[i];
                pref_val[i + 1] = pref_val[i];
            }
        }
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        // Process range queries
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            
            int shift = nz_count[r + 1] - nz_count[l];
            long long curr_sum = sum_digits[r + 1] - sum_digits[l];
            
            // Extract window value and safeguard against negative numbers in C++ modulo operations
            long long x = (pref_val[r + 1] - (pref_val[l] * pow10[shift]) % MOD + MOD) % MOD;
            
            ans.push_back((x * curr_sum) % MOD);
        }
        
        return ans;
    }
};
