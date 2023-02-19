#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6;
int N, q;
long long arr[maxN];
long long queries[maxN];

int firstOccurrence(long long elem) {
    int low = -1, high = N;

    while (high - low > 1) {
        int mid = (low + high) / 2;

        if (arr[mid] < elem)
            low = mid;
        else
            high = mid;
    }

    return high;
}

int lastOccurrence(long long elem) {
    int low = -1, high = N;

    while (high - low > 1) {
        int mid = (low + high) / 2;

        if (arr[mid] <= elem)
            low = mid;
        else
            high = mid;
    }

    return low;
}

int count(long long elem) {
    int fst = firstOccurrence(elem);
    int lst = lastOccurrence(elem);
    return lst-fst + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    cin >> q;
    for (int i = 0; i < q; i++)
        cin >> queries[i];

    sort(arr, arr + N);

    for (int i = 0; i < q; i++)
        cout << count(queries[i]) << "\n";

    return 0;
}