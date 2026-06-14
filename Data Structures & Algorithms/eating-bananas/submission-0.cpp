class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1, r = *max_element(piles.begin(), piles.end());
        while (l<r){
            int m = (l+r)/2;
            int t=0;
            for (int i=0; i<n; i++){
                t+=(piles[i]+m-1)/m;
            }
            if (t<=h) r=m;
            else l=m+1;
        }
        return l;
    }
};
