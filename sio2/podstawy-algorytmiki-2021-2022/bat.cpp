#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6;

int arr[maxN];
int N;
long long result = INT_MIN;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    int arr_max = INT_MIN;
    long long prefsum = 0;
    for (int i = 0; i < N; i++) {
        prefsum = max(0ll, prefsum + arr[i]);
        result = max(result, prefsum);
        arr_max = max(arr_max, arr[i]);
    }
    
    if (result == 0)
        result = arr_max;

    cout << result << "\n";
    return 0;
}