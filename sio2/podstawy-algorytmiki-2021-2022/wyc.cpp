#include <bits/stdc++.h>
using namespace std;

const int maxN = 10e5;
int n, k;
long long x[maxN];

bool is_distance_too_small(long long distance) {
    int day_cnt = 1;
    long long acc = x[0];
    
    for (int i = 1; i < n - 1; i++) {
        if (acc + x[i] <= distance) {
            acc += x[i];
        } else {
            acc = x[i];
            day_cnt++;
        }
    }

    return day_cnt > k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 0; i < n - 1; i++) 
        cin >> x[i];

    long long low = *max_element(x, x + n - 1) - 1;
    long long high = accumulate(x, x + n - 1, 0LL) + 1;
    long long mid;

    while (high - low > 1) {
        mid = (low + high) / 2;
        if (is_distance_too_small(mid)) // odfiltrować wszystkie za małe, brać pierwszy dostatecznie duży
            low = mid;
        else
            high = mid;
    }
    
    cout << high << "\n";
    return 0;
}
