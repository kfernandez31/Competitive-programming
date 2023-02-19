#include <bits/stdc++.h>
using namespace std;

using pip = pair<int, pair<int, int>>;

const int maxN = 3e5;
pip arr[maxN];
int n;

int solve_for_x(int i, int j) {
    // vector<pair<int, int>> xd;
    // for (int k = i; k <= j; k++) {
    //     xd.push_back({arr[k].second.first, k});
    //     xd.push_back({arr[k].second.second, k});
    // }
    // sort(xd.begin(), xd.end());
    // int open_cnt;
    // int cur = xd[0].second;

    int end = arr[i].second.second;
    int count = 1;

    for (int k = i; k <= j; k++) {
        if (arr[k].second.first < end) {
            count++;
        } else {
            end = arr[k].second.second;
        }
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first 
            >> arr[i].second.first 
            >> arr[i].second.second;
    }

    sort(arr, arr + n); 

    int res = 0;
    int i = 0;
    while (i < n) {
        int x = arr[i].first;
        int j = i;
        while (arr[j+1].first == x) {
            j++;
        }
        res += solve_for_x(i, j);
        i = j + 1;
    }

    cout << res << "\n";

    return 0;
}
