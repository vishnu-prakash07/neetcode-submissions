class Solution {
public:

    int solve(int i,vector<int>& prices,int bought,vector<vector<int>>& dp){
        if (i >= prices.size())
            return 0;
        if (dp[i][bought]!=-1)
            return dp[i][bought];
        int buy = INT_MIN;
        int sell = INT_MIN;
        if (bought == 0 )
            buy = -prices[i] + solve(i+1,prices,1,dp);
        if (bought == 1 )
            sell = prices[i] + solve(i+2,prices,0,dp);
        int skip = solve(i+1,prices,bought,dp);
        if (bought == 0)
            return dp[i][0] = max(buy,skip);
        else
            return dp[i][1] = max(sell,skip);
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solve(0,prices,0,dp);
    }
};
