#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5;
int n, k;
long x;
int d[maxN];

bool daSie() {
    int days = 0;

    int i = 0;
    while (i < n-1) {
        if (days > k)
            return false;

        long distLeft = x;
        while (i < n-1 && distLeft - d[i] >= 0) {
            distLeft -= d[i];
            i++;
        }
        days++;
    }
    return days <= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k >> x;
    for (int i = 0; i < n-1; i++)
        cin >> d[i];

    cout << (daSie()? "TAK" : "NIE") << "\n";

    return 0;
}
