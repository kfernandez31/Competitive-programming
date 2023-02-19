#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5;
int n, t;
double x;
int l[maxN], v[maxN];

bool daSie() {
    double timeAvlbl = t;
    for (int i = 0; i < n; i++) {
        timeAvlbl -= (double)l[i]/((double)v[i]+x);
        if (timeAvlbl < 0)
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> t >> x;
    for (int i = 0; i < n; i++)
        cin >> l[i] >> v[i];

    cout << (daSie()? "TAK" : "NIE") << "\n";

    return 0;
}