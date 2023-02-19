#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e3, maxM = 1e3;
int arr[maxN + 1][maxM + 1];
int dp[maxN + 1][maxM + 1];
int n, m;

void dp_run() {
    for (int i = 1; i <= n; i++) {     
        for (int j = 1; j <= m; j++) {
           dp[i][j] = arr[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    dp_run();

    int q;
    cin >> q;
    while (q--) {
        int a1, b1, a2, b2;
        cin >> a1 >> b1 >> a2 >> b2;
        int p1 = dp[a1 - 1][b1 - 1], p2 = dp[a1 - 1][b2], p3 = dp[a2][b1 - 1], p4 = dp[a2][b2];
        cout << p4 - p2 - p3 + p1 << "\n";
    }

    return 0;
}
