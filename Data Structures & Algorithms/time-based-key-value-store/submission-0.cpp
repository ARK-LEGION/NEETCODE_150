class TimeMap {
private:
    map<string, vector<pair<int,string>>> m;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if (m[key].empty()) return "";
        int l=0, r= m[key].size()-1;
        while (l<r){
            int mid = (l+r)/2;
            if(m[key][mid].first >= timestamp) r=mid;
            else l=mid+1;
        }
        if (m[key][l].first<=timestamp) return m[key][l].second;
        if (l-1>=0 && m[key][l-1].first<=timestamp) return m[key][l-1].second;
        return "";

    }
};
