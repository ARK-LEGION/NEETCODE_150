class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int s=0;
        for (int i=0; i<n; i++) s+=gas[i]-cost[i];
        if (s<0) return -1;
        int maxi=0;
        int start=0;
        for (int i=0;i<n; i++){
            if (s>maxi){
                maxi=s;
                start=i;
            }
            s-=(gas[i]-cost[i]);
        }
        return start;
    }
};
