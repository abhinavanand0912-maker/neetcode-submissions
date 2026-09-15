class Twitter {
public:
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;

    int time = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int, int, int>> pq;
        if(!tweets[userId].empty()){
            int idx=tweets[userId].size()-1;
            auto [timestamp, tweetId] = tweets[userId][idx];
            pq.push({timestamp,userId,idx});
        }
        for(int follow : following[userId]){
            if(!tweets[follow].empty()){
                int idx = tweets[follow].size() - 1;
                auto [timestamp, tweetId] = tweets[follow][idx];
                pq.push({timestamp, follow, idx});
            }
        }
        vector<int> feed;
        while(!pq.empty() && feed.size()<10){
            auto [timestamp,id,idx] = pq.top();
            pq.pop();
            feed.push_back(tweets[id][idx].second);
            if(idx>0){
                int newidx=idx-1;
                int newtime=tweets[id][newidx].first;
                pq.push({newtime, id, newidx});
            }
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
