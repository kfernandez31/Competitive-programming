#include <bits/stdc++.h>
using namespace std;

#define maxN 1000000

string slowo;
long long prefsum[maxN];
int prefvals[2 * maxN + 1];

long long result;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> slowo;
    int N = slowo.size();

    auto conv = [](char c){ return isupper(c)? 1 : -1; };
    auto newt = [](long long n){ return n*(n-1)/2; };

    prefsum[0] = conv(slowo[0]);
    for (int i = 1; i < N; i++) {
        int d = conv(slowo[i]);
        prefsum[i] = prefsum[i-1] + d;
    }
    
    for (int i = 0; i < N; i++) {
        prefvals[prefsum[i] + N]++;
    }

    result = prefvals[0 + N];
    for (int pv : prefvals) {
        result += newt(pv);
    }

    cout << result << "\n";
    return 0;
}