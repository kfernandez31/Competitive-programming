#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6;
int N, arr[maxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);

    int i = 0, j = N-1;
    while (i < j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }

    for (i = 0; i < N; i++)
        cout << arr[i] << " ";

    cout << "\n";
    return 0;
}
