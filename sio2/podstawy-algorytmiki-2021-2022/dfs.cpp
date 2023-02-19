#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5;
int n, m;
vector<int> graph[maxN + 1];
bool visited[maxN + 1];
stack<int> s;


void dfs_rec(int cur) {
    visited[cur] = true;

    for (auto next : graph[cur]) 
        if (!visited[next]) 
            dfs_rec(next);
}

void dfs_iter(int start) {  
    visited[start] = true;
    s.push(start); 

    while (!s.empty()) {
        int cur = s.top();
        s.pop();

        for (auto next : graph[cur]) 
            if (!visited[next]) {
                visited[next] = true;
                s.push(next);
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    
    dfs_iter(1);

    for (int i = 1; i <= n; i++) {
        cout << (visited[i]? "TAK" : "NIE") << "\n";
    }

    return 0;
}
