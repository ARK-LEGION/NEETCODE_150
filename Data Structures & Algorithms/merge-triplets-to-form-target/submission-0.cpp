class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        int m1=0, m2=0, m3=0;
        for (int i=0; i<n; i++){
            if(triplets[i][0]<=target[0] && triplets[i][1]<=target[1] && triplets[i][2]<=target[2]){
                m1=max(m1,triplets[i][0]);
                m2=max(m2,triplets[i][1]);
                m3=max(m3,triplets[i][2]);
            }
        }
        if (m1==target[0] && m2==target[1] && m3==target[2]) return true;
        return false;
    }
};
