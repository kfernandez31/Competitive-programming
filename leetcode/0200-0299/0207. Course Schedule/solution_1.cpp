// Approach: DFS w/3-coloring (taken from CRLS).
// TC: O(n+m)
// SC: O(n)
class Solution {
    #define WHITE 0
    #define GRAY  1
    #define BLACK 2
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<pair<int, vector<int>>> graph(numCourses);
        for (auto& p : prerequisites) {
            graph[p[1]].first = WHITE;
            graph[p[1]].second.push_back(p[0]);
        }

       function<void(int)> dfs = [&](int cur) {
            if (graph[cur].first == GRAY)
                throw 42; // found a cycle
            if (graph[cur].first == BLACK)
                return;
            graph[cur].first = GRAY;
            
            for (int next : graph[cur].second)
                dfs(next);
                
            graph[cur].first = BLACK;
            ordering.push_back(cur);
        };
        
        try {
            for (int i = 0; i < numCourses; ++i)
                dfs(i);
            return true;
        } catch (...) {
            return false;
        }
    }  
};