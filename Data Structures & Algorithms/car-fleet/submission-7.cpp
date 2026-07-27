class Solution {
public:

    vector<double> getTime(int n,const vector<vector<int>>& info,int target){
        //info = {pos,speed,i}
        vector<double> time;

        for (int i=0;i<n;i++){
            int distance = target - info[i][0];
            double timeCal = (double)distance / info[i][1];
            time.push_back(timeCal);
        }
        return time;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<double> time(n);
        vector<vector<int>> info(n);
        for (int i=0;i<n;i++){
            info[i]= {position[i],speed[i],i};
        }
        
        sort(info.begin(),info.end(),[](vector<int> &a,vector<int> &b){
            return a[0] > b[0];
        });

        time = getTime(n,info,target);

        double timeMax = 0.0;
        bool flag = false;
        int count = 0;

        for (int i=0;i<n;i++){
            flag = false;
            if (time[i] > timeMax){
                timeMax = time[i];
                count++;
            }
        }

        return count;
    }
};
