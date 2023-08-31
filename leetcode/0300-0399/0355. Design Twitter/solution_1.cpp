// Approach: A hashset is perfect for fast inserts and deletions, while a minheap serves well for getting the k greatest elements.
// TC: postTweet - O(1), follow - O(1), unfollow - O(1), getNewsFeed - O(f*t*log(NEWSFEED_SIZE)), f - max followee count, t - max twwet count
// SC: O(n(m+k)), n - users, m - avg. tweet count, k - avg. followee count
class Twitter {
    static constexpr size_t NEWSFEED_SIZE = 10;
    struct User {
        vector<pair<int, int>> tweets; // [(id -> time)]
        unordered_set<int> follows;
    };
    int cur_time = 0;
    unordered_map<int, User> users;
public:    
    void postTweet(int userId, int tweetId) {
        users[userId].tweets.push_back({tweetId, cur_time++});
    }
    
    void follow(int followerId, int followeeId) {
        users[followerId].follows.insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        users[followerId].follows.erase(followeeId);
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        // get own tweets
        for (auto& [id, time] : users[userId].tweets) {
            pq.push({-time, id});
            if (pq.size() == NEWSFEED_SIZE + 1)
                pq.pop();
        }
        // get followees' tweets
        for (int followee : users[userId].follows) {
            for (auto& [id, time] : users[followee].tweets) {
                pq.push({-time, id});
                if (pq.size() == NEWSFEED_SIZE + 1)
                    pq.pop();
            }
        }
        // unload the heap
        vector<int> ans(min(pq.size(), NEWSFEED_SIZE));
        for (int i = ans.size() - 1; i <= 0; --i) {
            ans[i] = pq.top().second; pq.pop();
        }
        return ans;
    }
};