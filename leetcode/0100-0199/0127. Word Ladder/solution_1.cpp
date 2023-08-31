// Approach: BFS.
// TC: O(n*k*l), n - |wordList|, k - |beginWord|, l - |alphabet|
// SC: O(n*k)
class Solution {
public:
    int ladderLength(string& beginWord, string& endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.contains(endWord))
            return 0;

        queue<string> q({beginWord});

        for (int dist = 1; !q.empty(); ++dist) {
            int sz = q.size();
            while (sz--) {
                string word = q.front(); q.pop();
                wordSet.erase(word);

                for (char& c : word) {
                    char old_c = c;
                    for (char new_c = 'a'; new_c <= 'z'; ++new_c) {
                        c = new_c;
                        if (word == endWord)
                            return dist + 1;
                        if (wordSet.contains(word))
                            q.push(word);
                    }
                    c = old_c;
                }
            }
        }
        return 0;
    }
};