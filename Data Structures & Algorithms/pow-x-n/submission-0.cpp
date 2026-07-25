class Solution {
public:

    double solve(double x,int n){
        if (n == 0)
            return 1.0;
        return x * solve(x,n-1);
    }

    double negSolve(double x,int n){
        if (n == 0)
            return 1.0;
        return 1.0/x * negSolve(x,n+1);
    }

    double myPow(double x, int n) {
        if (n < 0)
            return negSolve(x,n);
        return solve(x,n);
    }
};
