#include <bits/stdc++.h>
using namespace std;

const int maxN = 2*1e3;
const int maxM = 2*1e3;
int dp[maxN + 1][maxM + 1];
int n, m;
int nal1[maxN + 1], nal2[maxM + 1];
int pref1[maxN + 1], pref2[maxM + 1];

static inline int is_legal_coord(int x, int y) { 
    return 
        0 <= x && x <= n &&
        0 <= y && y <= m; 
}

int dp_run() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {   
            if (i == 0 && j == 0) 
                continue;

            int v1 = is_legal_coord(i - 1, j)? 
                nal1[i] + (pref1[i - 1] + pref2[j] - dp[i - 1][j]) : INT_MIN;
            int v2 = is_legal_coord(i, j - 1)?
                nal2[j] + (pref1[i] + pref2[j - 1] - dp[i][j - 1]) : INT_MIN;

            dp[i][j] = max(v1, v2);
        }
    }
   
    return dp[n][m];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> nal1[i];
        pref1[i] = pref1[i - 1] + nal1[i]; 
    }

    for (int i = 1; i <= m; i++) {
        cin >> nal2[i];
        pref2[i] = pref2[i - 1] + nal2[i]; 
    }

    cout << dp_run() << "\n";

    return 0;
}
