class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> mp;
        int n = nums.size();
        int valid = 0;
        for (int i=0;i<n;i++){
            if (!mp.count(nums[i])){
                mp.insert(nums[i]);
                swap(nums[valid],nums[i]);
                valid++;
            }
        }
        return valid;
    }
};