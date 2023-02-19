#include <bits/stdc++.h>
using namespace std;

const int maxN = 5e5;
const long long MOD = 1e9 + 7;
int workers[maxN + 1];
long long dp[maxN + 1];
long long pref[maxN + 1];
int n, k, l;

inline int safe_mod(int x) {
    return (x % MOD + MOD) % MOD;
}

inline bool represents(int a, int b) {
    return workers[a] - workers[b] <= k;
}

inline bool conflict(int a, int b) {
    return workers[a] - workers[b] < l;
}

pair<int, long long> solve() {
    int com_size = 0;

    sort(workers + 1, workers + n + 1);

    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
    }

    int member = 0, unrepr = 1;
    int prevLastPrev, lastPrev, lastCur;
    while (unrepr <= n) {
        lastPrev = member;
        member = unrepr;
        while (member + 1 <= n && represents(member + 1, unrepr)) {
            member++;
        }
        lastCur = member;

        com_size++;

        if (com_size > 1) {
            int left = prevLastPrev + 1;
            int l_range = left;
            int i_bound = left;
            int i_range = left;
            for (int i = lastPrev + 1; i <= member; i++) {
                while ((i_bound < lastPrev + 1) && !conflict(i, i_bound)) {
                    i_bound++;
                }

                while (!represents(i, i_range)) {
                    i_range++;
                }

                while (represents(l_range + 1, left)) {
                    l_range++;
                }
    
                while (l_range < i_range - 1) {
                    left++;
                    while (represents(l_range + 1, left)) {
                        l_range++;
                    }
                }

                dp[i] = (i_bound - 1 >= left) * (safe_mod(safe_mod(pref[i_bound - 1] - pref[left]) + dp[left]));
            }
        }

        for (int i = lastPrev + 1; i <= member; i++) {
            pref[i] = safe_mod(pref[i - 1] + dp[i]);
        }

        unrepr = member + 1;
        while (unrepr <= n && represents(unrepr, member)) {
            unrepr++;
        }

        prevLastPrev = lastPrev;
    }
    
    int firstLast = lastPrev + 1;
    while (!represents(n, firstLast)) {
        firstLast++;
    }
    int possibilities = safe_mod(safe_mod(pref[lastCur] - pref[firstLast]) + dp[firstLast]);
    return {com_size, possibilities};
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k >> l;

    for (int i = 1; i <= n; i++) {
        cin >> workers[i];
    }

    auto res = solve();
    cout << res.first << " " << res.second << "\n";

    return 0;
}