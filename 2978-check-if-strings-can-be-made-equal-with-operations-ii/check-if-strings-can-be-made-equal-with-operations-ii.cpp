class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.length();

        vector<int>freq1(26, 0), freq2(26, 0);
        for(int i=0; i<n; i++){
            if(i&1){
                freq1[s1[i]-'a']++;
            }
            else{
                freq2[s1[i]-'a']++;
            }
        }

        for(int i=0; i<n; i++){
            if(i&1){
                freq1[s2[i]-'a']--;
                if(freq1[s2[i]-'a'] < 0) return false;
            }
            else{
                freq2[s2[i]-'a']--;
                if(freq2[s2[i]-'a'] < 0) return false;
            }
        }

        return true;
    }
};