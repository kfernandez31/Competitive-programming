#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e3, maxM = 1e3;
int n, m;
int w[maxN + 1], v[maxN + 1];
int dp[maxN + 1][maxM + 1];

int solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (w[i] > j)
                dp[i][j] = dp[i - 1][j];
            else 
                dp[i][j] = max(dp[i - 1][j], v[i] + dp[i - 1][j - w[i]]);
        }
    }
    return dp[n][m];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
        cin >> w[i] >> v[i];
    
    cout << solve() << "\n";
    return 0;
}
