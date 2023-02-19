#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e6;
const int maxN = 1e3;
int board[maxN][maxN];
int dp[maxN + 1][maxN + 1];
int n;

inline int safe_mod(int x) {
return
    (x % MOD + MOD) % MOD;
}

bool is_valid_coord(int x, int y) {
return 
    (1 <= x && x <= n) && 
    (1 <= y && y <= n) &&
    board[x][y] == 0;
}

int compute_res() {
    dp[0][1] = 1;
    for (int i = 1; i <= n; i++) {     
        for (int j = 1; j <= n; j++) {
            if (is_valid_coord(i, j)) {
                dp[i][j] = safe_mod(dp[i - 1][j] + dp[i][j - 1]);
            }
        }
    }
    return safe_mod(dp[n][n]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }

    cout << compute_res() << "\n";

    return 0;
}
