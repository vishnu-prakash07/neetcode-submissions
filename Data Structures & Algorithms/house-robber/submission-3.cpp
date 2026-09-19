class Solution {
public:

    int solve(int i,vector<int>& dp,vector<int>& nums){
        int n = nums.size();
        if ( i >= n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int take = nums[i] + solve(i+2,dp,nums);
        int skip = solve(i+1,dp,nums);
        dp[i] = max(take,skip);
        return dp[i];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return solve(0,dp,nums);
    }
};
