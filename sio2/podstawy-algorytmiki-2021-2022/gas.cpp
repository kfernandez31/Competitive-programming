#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6;
int n, k;
bool arr[maxN];

int caterpillar() {
    int min_res = INT_MAX,
        tail = 0,
        head = 0,
        cnt[] = {0, 0};
    cnt[arr[0]] = 1;

    while (head < n) {
        if (cnt[1] < k) {
            head++;
            if (head < n) 
                cnt[arr[head]]++;
        } else {
            min_res = min(min_res, cnt[0]);
            cnt[arr[tail]]--;
            tail++;
        }
    }
    return (min_res == INT_MAX)? -1 : min_res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int res = caterpillar();
    if (res != -1)
        cout << res << "\n";
    else 
        cout << "NIE" << "\n";

    return 0;
}
