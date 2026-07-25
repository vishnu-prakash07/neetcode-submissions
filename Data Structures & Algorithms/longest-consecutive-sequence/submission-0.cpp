class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //using unordered_set/hashmap
        unordered_set<int> arr(nums.begin(),nums.end()); //duplicates removed

        int largest=0;
        int length;

        for (int num: nums){
            if(arr.count(num-1)==0) //num-1 won't exist in the array for being the starting member of a sequence
            {
                length=1;
                int current=num;

                while (arr.count(current+1)){
                    length++;
                    current++;
                }
            }
            largest=max(largest,length);
        }
        return largest;
    }
};
