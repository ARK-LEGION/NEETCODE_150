class Solution {
public:
    int reverse(int x) {
        int res=0;
        while (x){
            int pop = x%10;
            x/=10;
            if (!((res>=0 && (res<=INT_MAX/10 && 10*res<=INT_MAX-pop )) || (res<0 && (res>=INT_MIN/10) && (10*res >= INT_MIN-pop)))) return 0;
            res = res*10+pop;
        }
        return res;
    }
};
