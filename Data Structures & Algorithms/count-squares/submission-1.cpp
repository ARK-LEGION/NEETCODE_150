class CountSquares {
private:
    vector<vector<int>> horizontal;
    vector<vector<int>> freq;

public:
    CountSquares() {
        freq.assign(1001, vector<int>(1001, 0));
        horizontal.assign(1001, vector<int>());
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        if (freq[x][y]==0) horizontal[x].push_back(y);
        freq[x][y]++;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int  y= point[1];
        int ans=0;
        for (auto u:horizontal[x]){
            int d = abs(u-y);
            if (d==0) continue;
            int f2 = freq[x][u];
            int f3 = (x+d<=1000 ? freq[x+d][y] : 0);
            int f4 = (x+d<=1000 ? freq[x+d][u] : 0);
            ans+=f2*f3*f4;
            int f5 = (x-d>=0 ? freq[x-d][y] : 0);
            int f6 = (x-d>=0 ? freq[x-d][u] : 0);
            ans+=f2*f5*f6;
        }
        return ans;
    }
};
