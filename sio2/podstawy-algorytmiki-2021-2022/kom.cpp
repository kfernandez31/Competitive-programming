#include <bits/stdc++.h>
using namespace std;

struct q_el {
    int index;
    long long value;
};

const int maxN = 5e6;
int arr[maxN + 1];
deque<q_el> q;
int n, k;
long long a, b, MOD;

inline long long safe_mod(long long x) {
    return ((x % MOD) + MOD) % MOD;
}

void push(int idx, long long x) {
    while (!q.empty() && q.front().value < x) 
        q.pop_front();
    q.push_front({idx, x});
    while (!q.empty() && q.back().index - idx > k) 
        q.pop_back();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k >> a >> b >> MOD >> arr[1]; 
    for (int i = 2; i <= n; i++) 
        arr[i] = safe_mod(a * arr[i - 1] + b);
    
    long long result = 0;
    for (int i = n; i >= 1; i--) {
        push(i, arr[i]);
        result += q.back().value;
    }        
    cout << result << "\n";
}
