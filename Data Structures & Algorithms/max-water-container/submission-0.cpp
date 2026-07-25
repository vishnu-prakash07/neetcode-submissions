class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int left=0,right=n-1;
        int area=0,largest=0;
        while (left<right){
            int h=min(heights[left],heights[right]);
            int len=right-left;
            area=h*len;
            if (heights[left]>heights[right])
                right--;
            else
                left++;
            largest=max(area,largest);
        }
        return largest;
    }
};
