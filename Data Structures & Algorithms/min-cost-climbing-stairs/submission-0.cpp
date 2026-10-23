class Solution {
public:
    int solve(int i,vector<int>& dp,vector<int>& cost){
        int n = cost.size();
        if ( i >= n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int plusOne = solve(i+1,dp,cost);
        int plusTwo = solve(i+2,dp,cost);

        int best = min(plusOne,plusTwo);

        return dp[i] = best + cost[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        return min(solve(1,dp,cost),solve(0,dp,cost));
    }
};
