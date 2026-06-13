class Solution {
public:
    bool isHappy(int n) {
        vector<int> seen(1001,0);
        while (n){
            int r=0;
            while (n){
                r+=(n%10)*(n%10);
                n/=10;
            }
            if (seen[r]) break;
            if (r==1) return true;
            seen[r]=1;
            n=r;
        }
        return false;
    }
};
