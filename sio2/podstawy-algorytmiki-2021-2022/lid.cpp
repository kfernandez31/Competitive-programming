#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5;
int arr[maxN + 1];
int n;

bool is_leader(int x) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += (arr[i] == x);
    }
    return cnt > n / 2;
}

int get_candidate() {
    int top_val, top_cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (top_cnt == 0) {
            top_val = arr[i];
        }

        if (top_val == arr[i]) {
            top_cnt++;
        } else {
            top_cnt--;
        }
    }
    return top_cnt? top_val : -1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int x = get_candidate();
    if (is_leader(x)) {
        cout << x << "\n";
    } else {
        cout << "NIE\n";
    }

    return 0;
}
