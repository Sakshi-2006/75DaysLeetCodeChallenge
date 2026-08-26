class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l=0, r=0, ones=0, n=s.size(), minlen=INT_MAX;//use two pointers l and r with a ones counter                             //6
        string ans="";//base case
        while(r<n){//0<9 1<9 2<9 3<9 4<9 5<9 6<9 7<9 8<9 9!<9
            //expand r, if s[r] is 1 increment ones
            if(s[r]=='1') ones++;//1 2 3 3
            while(ones==k){//1!=3 still still still still 3==3 2!=3 still still 3=3 3=3 3=3 3=3
                if(r-l+1<=minlen){//5-0+1=6<=6 8-1+1=8!<=6 8-2+1=7!<=6 8-3+1=6<=6 8-4+1=5<=6
                    if(r-l+1==minlen){//6==6 6==6  
                        if(ans>s.substr(l,r-l+1)) ans=s.substr(l,r-l+1); //no no
                    }                //(0,6)
                    else ans=s.substr(l,r-l+1);//(0,6) (1,8) (2,8) (4,8)
                    minlen=r-l+1;//6 8 6 5
                }
                if(s[l]=='1') ones--;//2 2
                l++;//1 2 3 4 5
            }
            r++;//1 2 3 4 5 6 7 8 9
        }
        return ans;
    }
};