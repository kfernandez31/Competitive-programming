// Approach: Find the largest component with DFS.
// TC: O(n)
// SC: O(n)
class Solution {
    unordered_map<int, vector<int>> graph;
    unordered_map<int, bool> visited;
    
    int dfs(int cur) {
        int subtree_size = 1;
        visited[cur] = true;
        for (int next : graph[cur])
            if (!visited[next]) 
                subtree_size += dfs(next);
        return subtree_size;
    }
public:
    int longestConsecutive(vector<int>& nums) {
        for (int num : nums) 
            graph.insert({num, {}});
        
        for (int num : nums) {
            if (graph.count(num - 1))
                graph[num].push_back(num - 1);
            if (graph.count(num + 1))
                graph[num].push_back(num + 1);
        }

        int max_comp_size = 0;
        for (int num : nums) 
            if (!visited[num])
                max_comp_size = max(max_comp_size, dfs(num));
        
        return max_comp_size;
    }
};