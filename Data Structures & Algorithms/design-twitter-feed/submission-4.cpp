class Twitter {
    int time=0;
    unordered_map<int,set<int>> followee;
    vector<priority_queue< pair<int,int> >> tweets;
public:
    Twitter() {
        tweets.resize(101);
        for (int i=1; i<=100; i++){
            followee[i].insert(i);
        }
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        tweets[userId].push({time, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        for (auto i:followee[userId]){
    
            vector<pair<int,int>> temp;
            int sz = tweets[i].size();
            for (int j=0; j<min(10,sz); j++){
                pq.push(tweets[i].top());
                temp.push_back(tweets[i].top());
                tweets[i].pop();
            }
            while (!temp.empty()){
                tweets[i].push(temp.back());
                temp.pop_back();
            }
        }
        int x  = pq.size();
        vector<int> ans;
        for (int j=0; j<min(10,x); j++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if (followeeId == followerId) return;
        followee[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followeeId == followerId) return;
        followee[followerId].erase(followeeId);
    }
};
