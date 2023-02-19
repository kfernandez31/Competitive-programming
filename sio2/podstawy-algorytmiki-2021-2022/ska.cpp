#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e2;
const int maxX = 1e4;
int n;
int w[maxN];
pair<int, int> dp[maxX + 1];

void solve() {
    for (int i = 1; i <= maxX; i++) {
        dp[i].first = INT_MAX;
        for (int j = 0; j < n && w[j] <= i; j++) {
            if (dp[i - w[j]].first < dp[i].first - 1) {
                dp[i] = {1 + dp[i - w[j]].first, w[j]};
            }
        }
    }
}

vector<int> get_res(int x) {
    vector<int> res;

    while (x) {
        if (dp[x].second == 0) {
            return {};
        }
        res.push_back(dp[x].second);
        x -= dp[x].second;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    sort(w, w + n);
    solve(); 

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        if (x == 0) {
            cout << "0\n";
        } else {
            vector<int> res = get_res(x);
            if (!res.empty()) {
                cout << res.size() << " ";
                for (int e : res) {
                    cout << e << " ";
                }
                cout << "\n";
            } else {
                cout << "-1\n";
            }
        }
    }
    
    return 0;
}
