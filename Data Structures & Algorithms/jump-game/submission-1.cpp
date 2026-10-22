class Solution {
public:
    bool solve(int i,vector<int>& dp,vector<int>& nums){
        int n = nums.size();
        if (i >= n-1)
            return true;
        if (dp[i] != -1)
            return dp[i];
        int length = nums[i];
        for (int j=1;j<=length;j++){
            if (solve(i+j,dp,nums))
                return dp[i] = 1;
        }
        return dp[i] = 0;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(0,dp,nums);
    }
};
