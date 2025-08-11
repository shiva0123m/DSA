#include <bits/stdc++.h>
using namespace std;

class Twitter {
private:
    vector<pair<int,int>> tweets; 
    unordered_map<int, unordered_set<int>> following; 

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        for (int i = tweets.size() - 1; i >= 0 && feed.size() < 10; i--) {
            int user = tweets[i].first;
            if (user == userId || following[userId].count(user)) {
                feed.push_back(tweets[i].second);
            }
        }
        return feed;
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
