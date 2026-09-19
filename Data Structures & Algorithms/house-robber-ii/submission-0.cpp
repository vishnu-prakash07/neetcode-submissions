class Solution {
public:

    int solve(int i,int end,vector<int>& dp,vector<int>& nums){
        if ( i > end)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int take = nums[i] + solve(i+2,end,dp,nums);
        int skip = solve(i+1,end,dp,nums);

        dp[i] = max(take,skip);
        return dp[i];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if ( n == 1)
            return nums[0];
        //case1 - 0 to n-2
        vector<int> dp1(n , -1);
        int case1 = solve(0,n-2,dp1,nums);

        //case2 - 1 to n-1
        vector<int> dp2(n, -1);
        int case2 = solve(1,n-1,dp2,nums);

        return max(case1,case2);
    }
};
