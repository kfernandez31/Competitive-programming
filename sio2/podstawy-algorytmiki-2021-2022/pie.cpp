#include <bits/stdc++.h>
using namespace std;

unsigned long long n;

unsigned long long pierw(unsigned long long x) {
//    O(n^{1/2}):
//    int i = 1;
//    for (; i * i < n; i++);
//    cout << i << "\n";

    unsigned long long low = 0, high = x;
    while (high - low > 1) {
        unsigned long long mid = (low + high) / 2;
        if (mid * mid <= x)
            low = mid;
        else
            high = mid;
    }
    return high;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    cout << pierw(n) << "\n";

    return 0;
}
