#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9;
const int maxN = 1e3;
int n;
int xs[maxN];
int left_dp[maxN][maxN];
int right_dp[maxN][maxN];

inline int safe_mod(int x) {
return
    (x % MOD + MOD) % MOD;
}

int solve() {
    for (int d = 0; d < n; d++) {
        for (int i = 0, j = i + d; j < n; i++, j++) {
            if (i == j)
                left_dp[i][j] = right_dp[i][j] = 1;
            else if (j - i >= 1) {
                if (xs[i] < xs[i + 1]) 
                    left_dp[i][j]  = safe_mod(left_dp[i][j]  + left_dp[i + 1][j]);
                if (xs[j - 1] < xs[j]) 
                    right_dp[i][j] = safe_mod(right_dp[i][j] + right_dp[i][j - 1]);

                if (j - i >= 2 && xs[i] < xs[j]) {
                    left_dp[i][j]  = safe_mod(left_dp[i][j]  + right_dp[i + 1][j]);
                    right_dp[i][j] = safe_mod(right_dp[i][j] + left_dp[i][j - 1]);
                }
            }
        }
    }
    return safe_mod(left_dp[0][n - 1] + (n > 1) * right_dp[0][n - 1]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> xs[i];
    }
    cout << solve() << "\n";
}