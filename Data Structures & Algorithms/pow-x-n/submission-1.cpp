class Solution {
public:

    double solve(double x,int n){
        if (n == 0)
            return 1.0;
        double half = solve(x,n/2);

        if (n%2 == 0)
            return half * half;
        return half * half * x;
    }

    double myPow(double x, int n) {
        if (n < 0)
            return solve(1/x,-n);
        return solve(x,n);
    }
};
