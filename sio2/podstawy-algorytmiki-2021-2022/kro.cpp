#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6;
int m[maxN];
long long dp[2][maxN];
int n;

long long dp_run() {
    dp[1][0] = m[0];
    for (int i = 1; i < n; i++) {
        dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]);
        dp[1][i] = dp[0][i - 1] + m[i];
    }
    return max(dp[0][n - 1], dp[1][n - 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> m[i];

    cout << dp_run() << "\n";

    return 0;
}
