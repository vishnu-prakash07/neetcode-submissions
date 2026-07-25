class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int profit=0;

        for (int i=1;i<prices.size();i++){
            buy=min(prices[i],buy);
            profit=max(profit,prices[i]-buy);//by selling our product today will make more profit or not!?
        }
        return profit;
    }
};
