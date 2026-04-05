class Solution {
public:
    bool judgeCircle(string moves) {
       unordered_map<char,int> mp;
       for(auto x:moves)
       {
        mp[x]++;
       } 
       if(mp['L']==mp['R'] && mp['U']==mp['D'])
       return true;
       return false;
    }
};