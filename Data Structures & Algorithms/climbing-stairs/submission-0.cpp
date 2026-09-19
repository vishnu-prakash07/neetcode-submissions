class Solution {
public:

    int solve(int n,vector<int>& dp){
        if (n == 0)
            return 1;
        if ( n == 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        int take1 = solve(n - 1 , dp);
        int take2 = solve(n - 2 , dp);
        dp[n] = take1 + take2;
        return dp[n];
    }

    int climbStairs(int n) {
        vector<int> dp(n+1 , -1);
        int ans = solve(n,dp);
        return ans;
    }
};
