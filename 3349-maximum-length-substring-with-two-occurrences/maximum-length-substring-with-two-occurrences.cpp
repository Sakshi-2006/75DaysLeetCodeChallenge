class Solution {
public:
    int maximumLengthSubstring(string s) {
        //a-->freq[0]....z-->freq[25]
        int freq[26]={0};
        int left,ans=0;
        for(int right=0;right<s.size();right++){//0 1
            freq[s[right]-'a']++;
            while(freq[s[right]-'a']>2){
                freq[s[left]-'a']--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};