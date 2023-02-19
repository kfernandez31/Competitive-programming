#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6;

int arr[maxN];
int prefsum[maxN];
int fst[maxN], snd[maxN], ans[maxN];
int n,q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < q; i++)
        cin >> fst[i] >> snd[i];

    prefsum[0] = arr[0];
    for (int i = 1; i < n; i++)
        prefsum[i] = prefsum[i-1] + arr[i];

    for (int i = 0; i < q; i++) {
        ans[i] = prefsum[snd[i]-1] - prefsum[fst[i]-1] + arr[fst[i]-1];
    }

    for (int i = 0; i < q; i++)
        cout << ans[i] << "\n";

    return 0;
}
