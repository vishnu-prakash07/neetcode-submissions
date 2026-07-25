class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (triplets[i][0] <= target[0] && triplets[j][0] <= target[0] && 
                triplets[i][1] <= target[1] && triplets[j][1] <= target[1] &&
                triplets[i][2] <= target[2] && triplets[i][2] <= target[2]){
                    triplets[j][0] = max(triplets[i][0],triplets[j][0]);
                    triplets[j][1] = max(triplets[i][1],triplets[j][1]);
                    triplets[j][2] = max(triplets[i][2],triplets[j][2]);
                }
            }
        }
        if (find(triplets.begin(),triplets.end(),target) == triplets.end())
            return false;
        return true;
    }
};
