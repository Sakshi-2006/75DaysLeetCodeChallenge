class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minsofar =INT_MAX,heymax =0,profit;
        for(int i=0;i<prices.size();i++){
            minsofar=min(prices[i],minsofar);
            profit=prices[i]-minsofar;
            heymax=max(profit,heymax);
        }
        return heymax;
    }
};