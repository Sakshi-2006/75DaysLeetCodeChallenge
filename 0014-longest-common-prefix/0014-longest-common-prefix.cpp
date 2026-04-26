class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s1=strs[0];
    int ans_length=s1.size();
    for(int i=1;i<strs.size();i++){
        int j=0;
        while(j<s1.size() && j<strs[i].size()&& s1[j]==strs[i][j]){
            j++;
            //
        }
        ans_length=min(ans_length,j);
    }
    string ans= s1.substr(0,ans_length);
    return ans;
    }
};