#include <bits/stdc++.h>
using namespace std;

const int maxN = 30000 / 2;
int N;
set<int> graph[maxN];

void checkIfEdgeExists(int a, int b) {
    auto srch = graph[min(a,b)].find(max(a,b));
    if (srch != graph[min(a,b)].end())
        printf("TAK\n");
    else 
        printf("NIE\n");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[min(v1, v2)].insert(max(v1,v2));
    }

    int z, a, b;
    cin >> z;
    while (z--) {
        cin >> a >> b;
        checkIfEdgeExists(a, b);
    }

    return 0;
}
