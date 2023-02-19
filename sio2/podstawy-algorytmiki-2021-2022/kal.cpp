#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6;
int n, m, z;
int a[maxN + 1], b[maxN + 1];
int prefA[maxN + 1], prefB[maxN + 1];

void convert(int di, int mi, char ci) {
    int day, month, absDays;
    int *pre, *post;
    int low = -1, high;
    
    if (ci == 'A') {
        pre = prefA;
        post = prefB;
        high = m+1;
    }
    else {
        pre = prefB;
        post = prefA;
        high = n+1;
    }

    absDays = pre[mi-1] + di;

    while (high - low > 1) {
        int mid = (low + high) / 2;
        
        if (post[mid] < absDays)
            low = mid;
        else
            high = mid;
    }
    month = high;
    day = absDays - post[high-1];

    cout << day << " " << month << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    cin >> z;

    prefA[1] = a[1];
    for (int i = 2; i <= n; i++)
        prefA[i] = prefA[i-1] + a[i];

    prefB[1] = b[1];
    for (int i = 2; i <= m; i++)
        prefB[i] = prefB[i-1] + b[i];

    for (int i = 0; i < z; i++) {
        int di, mi;
        char ci;
        cin >> di >> mi >> ci;
        convert(di, mi, ci);
    }

    return 0;
}
