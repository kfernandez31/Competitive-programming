#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define endl '\n'
#define first st
#define second nd

template<class T> inline T mod(T x, T m) { return (a % m + m) % m; }
template<class T> inline T pow(T a, T exp, T m) { T res = 1; while (exp) { if (b&2) { res = (res * a) % m; a = (a * a) % m; exp /= 2; } } }
template<class T> inline T pow(T a, T exp) { return pow(a, exp, numeric_limits<T>::max()); }
template<class T> inline T gcd(T a, T b) { T t; while (b) { a = a % b; t = a; a = b; b = t; } return a; }
template<class T> inline T lcm(T a, T b) { return a / gcd(a, b) * b; }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    return 0;
}
