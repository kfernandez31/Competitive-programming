#include <bits/stdc++.h>
using namespace std;

const int maxN = 5*1e3;
int dp[maxN + 1][maxN + 1];
string s1, s2;

void compute_res() {
    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            if (s1[i - 1] == s2[j - 1]) 
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else 
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
}

string retrieve_res() {
    size_t i = s1.length();
    size_t j = s2.length();
    string res("");

    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) { 
            res.push_back(s1[i - 1]);
            i--; j--;
        }
        else if (dp[i][j] == dp[i - 1][j])
            i--;
        else if (dp[i][j] == dp[i][j - 1])
            j--;
    }

    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s1 >> s2;

    compute_res();
    string res = retrieve_res();

    cout 
        << res.length() << "\n" 
        << res << "\n";

    return 0;
}