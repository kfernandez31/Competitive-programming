// Approach: Nondeterministic finite automaton.
// TC: O(3^n)
// SC: O(n)
class NFA {
    #define EPS '\0'
    vector<unordered_map<char, int>> graph;
public:
    NFA(string& pat) : graph(1) {
        for (int i = 0; i < pat.size(); ++i) {
            char c = pat[i];
            if (islower(c) || c == '.') {
                graph.emplace_back();
                graph.back()[c] = graph.size();
            } else if (c == '*' && i > 0) {
                graph.back()[pat[i - 1]] = graph.size() - 1;
                graph.back()[EPS]        = graph.size();
            }
        }
    }

    bool match(string& s, int i = 0, int state = 1) {    
        if (state == 0)
            return false;         // rejecting state

        if (state == graph.size())
            return i == s.size(); // accepting state
        
        if (i == s.size()) {
            if (state == graph.size())
                return true;
            return match(s, i, graph[state][EPS]);
        }

        return match(s, i + 1, graph[state][s[i]])
            || match(s, i + 1, graph[state]['.'])
            || match(s, i,     graph[state][EPS]);
    }
};

class Solution {
public:
    bool isMatch(string& s, string& p) {
        if (p == ".*")
            return true;
        return NFA(p).match(s);
    }
};
