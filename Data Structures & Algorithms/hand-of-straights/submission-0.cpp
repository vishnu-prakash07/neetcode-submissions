class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if ( n % groupSize )
            return false;
        map<int,int> freq;

        for (int x : hand)
            freq[x]++;

        while (!freq.empty()){
            int first = freq.begin()->first;
            for (int x = first ; x < first + groupSize ; x++){
                if (freq.find(x) == freq.end())
                    return false;
                freq[x]--;
                if (freq[x] == 0)
                    freq.erase(x);
            }
        }
        return true;
    }
};
