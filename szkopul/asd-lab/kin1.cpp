#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9;
const int maxN = 2e4;
const int maxK = 10;

int arr[maxN + 1];
int dp[maxN + 1][maxK + 1];
int n, k;

inline static int safe_mod(int x) {
    return (x % MOD + MOD) % MOD;
}

int solve() {
    for (int i = 1; i <= n; i++) {
        dp[i][1] = 1;
    }

    for (int i = 2; i <= k; i++) { // range of `k`
        for (int j = i; j <= n; j++) { // end of subarray
            for (int l = i - 1; l < j; l++) { // end of smaller subarray
                dp[j][i] = safe_mod(dp[j][i] + (arr[l] > arr[j]) * dp[l][i - 1]);
            }
        }
    }

    int cnt = 0;
    for (int i = k; i <= n; i++) {
        cnt = safe_mod(cnt + dp[i][k]);
    }

    return cnt;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    cout << solve() << "\n";

    return 0;
}
