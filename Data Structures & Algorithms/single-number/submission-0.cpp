class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (auto &val : nums)
            ans = ans ^ val;
        return ans;
    }
};
