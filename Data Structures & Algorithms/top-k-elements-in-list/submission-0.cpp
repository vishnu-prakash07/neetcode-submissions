class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        int n = nums.size();
        if ( k == n)
            return nums;
        for (int i=0;i<n;i++)
            hash[nums[i]]++; //frequency!
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for (auto &it : hash)
            pq.push({it.second,it.first});
        
        while (pq.size() > k)
            pq.pop();
        
        vector<int> ans;
        while (!pq.empty()){
            auto [freq,key] = pq.top();
            ans.push_back(key);
            pq.pop();
        }
        
        return ans;
    }
};
