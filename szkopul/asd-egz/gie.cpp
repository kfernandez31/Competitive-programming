#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define NONE 0
#define endl '\n';

const int maxN = 5e5;
ll arr[maxN + 1];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll res = 0;
    ll bought = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i + 1] == arr[i]) {
            continue;
        } else if (bought == -1 && i < n - 1 && arr[i + 1] > arr[i]) {
            bought = arr[i];
        } else if (bought != -1 && arr[i + 1] < arr[i]) {
            res += arr[i] - bought;
            bought = -1;
        }
    }

    cout << res << endl;

    return 0;
}
