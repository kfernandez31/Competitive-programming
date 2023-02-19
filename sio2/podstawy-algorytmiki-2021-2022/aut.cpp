#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5, maxV = 5*1e4;
int n, t;
int l[maxN];
long double speedLimit[maxN], v[maxN];

long double przekroczenie() {
    long double timeSum = 0;

    for (int i = 0; i < n; i++)
        timeSum += l[i]/speedLimit[i];

    long double low = 0, high = maxV + DBL_MIN;
    while (high - low > 1e-6) {
        long double mid = (low + high) / 2;

        timeSum = 0;
        for (int i = 0; i < n; i++) {
            v[i] = speedLimit[i] + mid;
            timeSum += l[i]/v[i];
        }

        if (timeSum > t)
            low = mid;
        else
            high = mid;
    }

    return high;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> t;
    for (int i = 0; i < n; i++)
        cin >> l[i] >> speedLimit[i];

    cout << fixed << setprecision(9) << przekroczenie() << "\n";

    return 0;
}

