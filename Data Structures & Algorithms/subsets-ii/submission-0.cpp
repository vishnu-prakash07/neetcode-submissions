class Solution {
    vector<vector<int>> res;
public:

    void solve(int index,vector<int>& ans,vector<int>& nums){
        res.push_back(ans);
        for (int i=index;i<nums.size();i++){
            if (i>index && nums[i] == nums[i-1])
                continue;
            ans.push_back(nums[i]);
            solve(i+1,ans,nums);
            ans.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        solve(0,ans,nums);
        return res;
    }
};
