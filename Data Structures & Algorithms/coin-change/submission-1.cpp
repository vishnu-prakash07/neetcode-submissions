class Solution {
public:

    int solve(int amount,vector<int>& coins,vector<int>& dp){
        if (amount == 0)
            return 0;//as there is no need of coins if the amount req already reduced to 0
        if (amount < 0)
            return INT_MAX;
        if (dp[amount] != -1)
            return dp[amount];
        int ans = INT_MAX;
        for (int val : coins){
            int res = solve( amount - val , coins ,dp);

            if (res != INT_MAX)
                ans = min(ans , res + 1);
        }
        return dp[amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);//all not calculated amount is -1
        int ans = solve(amount ,coins ,dp);
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};
