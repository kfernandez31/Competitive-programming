#include <bits/stdc++.h>
using namespace std;

using uint = unsigned;
using ll   = long long;
using ull  = unsigned ll;
using pii  = pair<int, int>;

#define endl         "\n"
#define fast_io      ios_base::sync_with_stdio(0); cin.tie(0)
#define first        st
#define second       nd
#define ALPHABET_LEN 26

inline int ctoi(char c) { return c - 'a'; }
template<class T> inline T mod(T a, T m) { return (a % m + m) % m; }
template<class T> inline T pow(T a, T b, T m) { T res = 1; while (b) { if (b&1) { res = (res * a) % m; a = (a * a) % m; b >>= 1; } } }
template<class T> inline T pow(T a, T b) { return pow(a, b, numeric_limits<T>::max()); }
template<class T> inline T gcd(T a, T b) { T t; while (b) { a = a % b; t = a; a = b; b = t; } return a; }
template<class T> inline T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<typename Arr, typename Len> inline void print_arr(const Arr& arr, const Len len, const char* sep) {
    for (Len i = 0; i < len; i++)
        cout << arr[i] << sep;
    cout << endl;
}

int main() {
    fast_io;

    return 0;
}
