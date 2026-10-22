class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int start = 0,end = people.size() - 1;
        int count = people.size();
        int boatCount = 0;
        while (count > 0){
            int total = people[start] + people[end];
            if (total > limit){
                count--;
                end--;
            }
            else{
                count -= 2;
                end--;
                start++;
            }
            boatCount++;
        }
        return boatCount;
    }
};