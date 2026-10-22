class Solution {
public:

    void solve(vector<int>& curr,vector<vector<int>>& ans,vector<int>& nums,vector<bool>& used){
        if (curr.size() == nums.size()){
            ans.push_back(curr);
            return;
        }
        int n = nums.size();
        for(int i=0;i<n;i++){
            if (used[i])
                continue;
            
            if (i>0 && nums[i] == nums[i-1] && !used[i-1])
                continue;
            
            used[i] = true;
            curr.push_back(nums[i]);
            solve(curr,ans,nums,used);
            curr.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;
        int n = nums.size();
        vector<bool> used(n,false);
        sort(nums.begin(),nums.end());
        solve(curr,ans,nums,used);
        return ans;
    }
};