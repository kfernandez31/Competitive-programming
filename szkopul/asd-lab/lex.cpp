#include <bits/stdc++.h>
using namespace std;

const int maxN = 3e5;
const int maxM = 3e5;
const long long P = 29;
const long long Q = 1e9+7;

long long ppow[maxN + 1];
long long shash[maxN + 1];
char s[maxN + 1];
int n, m;

inline long long safe_mod(long long x) {
    return (x % Q + Q) % Q;
}

inline long long get_hash(int a, int b) {
    return safe_mod(shash[b] - shash[a - 1] * ppow[b - a + 1]);
}

char solve(int a, int b, int c, int d) {
    int shorter_len = min(b - a + 1, d - c + 1);
    int low = 0, high = shorter_len;
    while (high - low > 0) {
        int mid = (high + low) / 2;
        if (get_hash(a, a + mid) == get_hash(c, c + mid)) {
            low = mid + 1;
        }else {
            high = mid;
        }
    }

    if (high == shorter_len) {
        return b - a < d - c? '<' : '>';
    } else {
        return s[a + high] < s[c + high]? '<' : '>';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    ppow[0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        ppow[i]  = safe_mod(ppow[i - 1] * P);
        shash[i] = safe_mod(shash[i - 1] * P + s[i] - 'a' + 1);
    }

    while (m--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << (get_hash(a, b) == get_hash(c, d)? '=' : solve(a, b, c, d)) << '\n';
    }

    return 0;
}
