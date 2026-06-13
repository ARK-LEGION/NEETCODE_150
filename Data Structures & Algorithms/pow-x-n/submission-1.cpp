class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        if (n==0) return 1;
        if (n<0){
            x = 1/x;
            n=abs(n);
        }
        while (n){
            if (n%2==0){
                x = x*x;
                n/=2;
            }
            else{
                ans*=x;
                x = x*x;
                n = (n-1)/2;
            }
        }
        return ans;
    }
};
