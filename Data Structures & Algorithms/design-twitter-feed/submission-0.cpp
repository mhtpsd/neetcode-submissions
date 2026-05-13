class Twitter {
public:

    int timer;

    unordered_map<int, unordered_set<int>> following;

    // userId -> {time, tweetId}
    unordered_map<int, vector<pair<int,int>>> tweets;

    Twitter() {
        timer = 0;
    }

    void postTweet(int userId, int tweetId) {

        tweets[userId].push_back({timer++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        priority_queue<pair<int,int>> pq;

        // user's own tweets
        for (auto &tweet : tweets[userId]) {
            pq.push(tweet);
        }

        // followed users' tweets
        for (int followee : following[userId]) {

            for (auto &tweet : tweets[followee]) {
                pq.push(tweet);
            }
        }

        vector<int> ans;

        int cnt = 10;

        while (!pq.empty() && cnt--) {

            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {

        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {

        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */