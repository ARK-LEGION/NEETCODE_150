class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int  n  = hand.size();
        if (n%groupSize!=0) return 0;
        int num = n/groupSize;
        map<int, int> m;
        for(int i=0; i<n; i++) m[hand[i]]++;
        vector<vector<int>>a(num);
        int start=0;
        for (int i=0; i<num; i++){
            for (auto &u:m){
                if (a[i].size()==groupSize) break;
                if ((a[i].empty() ||( u.first==a[i].back()+1 ))){
                    a[i].push_back(u.first);
                    u.second--;
                    if (u.second==0) m.erase(m.find(u.first));
                }

                else{
                    return false;
                }
            }
            if (a[i].size()<groupSize)return false;
            // cout<<"dnik"<<endl;
        }
        return true;
    }
};
