#include <bits/stdc++.h>
using namespace std;

#define MEAN(x, y) (((x)+(y))/2)
#define IS_EVEN(x) ((x)&1)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) __lcm(a,b)

//////////////////////////////////////////////////////////////////////////////////////////

const int maxN = 30000;
int N;
int graph[maxN + 1];
bool visited[maxN + 1];

int countCycles() {
    int result = 0;
    for (int i = 1; i <= N; i++) {
        if (visited[i]) {
            continue;
        }
        
        result++;
        int v = i;
        while (!visited[v]) {
            visited[v] = true;
            v = graph[v];
        }
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> graph[i];
    }

    cout << countCycles() << "\n";

    return 0;
}
