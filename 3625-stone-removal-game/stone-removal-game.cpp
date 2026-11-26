class Solution {
public:
    bool canAliceWin(int n) {

        bool alice = true;
        
        for(int i = 10 ; i>=0 ; i = i-2){

            if(n < i ) {
                alice = false ; // alice fail ;
                break;
            }   

            n -= i ; 

            if( n < (i-1)) return true ; // bob fails

            n -= (i-1); // subs. bob stones
            
        }
        
    return alice ;
        
    }
};