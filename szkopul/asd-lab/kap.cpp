#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5;

pair<int, int> coords[maxN + 1];
vector<int> graph[maxN + 1];
int dist[maxN + 1];
int xorder[maxN + 1];
int yorder[maxN + 1];
priority_queue<pair<int, int>> minheap;
int n;

inline int weight(int a, int b) {
    return min(abs(coords[a].first - coords[b].first), abs(coords[a].second - coords[b].second));
}

inline bool cmpX(int a, int b) {
    return coords[a] < coords[b]; 
}

inline bool cmpY(int a, int b) {
    pair<int, int> pa = {coords[a].second, coords[a].first};
    pair<int, int> pb = {coords[b].second, coords[b].first};
    return pa < pb; 
}

void dijkstra() {
    dist[1] = 0;
    minheap.push({0, 1});

    while (!minheap.empty()) {
        int v = minheap.top().second;
        minheap.pop();

        for (int nbr : graph[v]) {
            int curdist = weight(v, nbr);
            if (dist[v] + curdist < dist[nbr]) {
                dist[nbr] = dist[v] + curdist;
                minheap.push({-dist[nbr], nbr});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        coords[i] = {x, y};
        xorder[i] = yorder[i] = i;
        dist[i] = INT_MAX;
    }

    sort(xorder + 1, xorder + n + 1, cmpX);
    sort(yorder + 1, yorder + n + 1, cmpY);

    graph[xorder[1]].push_back(xorder[2]);
    graph[xorder[n]].push_back(xorder[n - 1]);
    graph[yorder[1]].push_back(yorder[2]);
    graph[yorder[n]].push_back(yorder[n - 1]);
    for (int i = 2; i <= n - 1; i++) {
        graph[xorder[i]].push_back(xorder[i - 1]);
        graph[xorder[i]].push_back(xorder[i + 1]);
        graph[yorder[i]].push_back(yorder[i - 1]);
        graph[yorder[i]].push_back(yorder[i + 1]);
    }

    dijkstra();

    cout << dist[n] << "\n";

    return 0;
}
