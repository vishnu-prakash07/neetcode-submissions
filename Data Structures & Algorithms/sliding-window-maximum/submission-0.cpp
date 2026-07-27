class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        // int maxNum = INT_MIN;
        int start = 0;
        int end = k-1;
        vector<int> res;
        while (end < n){
            int maxNum = INT_MIN;
            for (int i=start;i<=end;i++){
                maxNum = max(nums[i],maxNum);
            }
            start++;
            end++;
            res.push_back(maxNum);
        }
        return res;
    }
};
