#include <bits/stdc++.h>
using namespace std;

int t;
const int maxN = 1e6;
int sieve[maxN + 1];
int lowestDiv[maxN + 1];

void prepareLowestDivArray() {
    for (int i = 2; i * i <= maxN; i++) {
        if (lowestDiv[i] == 0) {
            for (int k = i * i; k <= maxN; k += i) {
                if (lowestDiv[k] == 0) {
                    lowestDiv[k] = i;
                }
            }
        }
    }
}

void factor(int n) {
    while (lowestDiv[n] > 0) {
        cout << lowestDiv[n] << " ";
        n /= lowestDiv[n];
    }
    if (n != 1) 
        cout << n;

    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    prepareLowestDivArray();
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        factor(n);
    }

    return 0;
}

