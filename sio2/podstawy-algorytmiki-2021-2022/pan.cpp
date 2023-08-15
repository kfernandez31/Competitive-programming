#include <bits/stdc++.h>
using namespace std;

using uint = unsigned;
using ll   = long long;
using ull  = unsigned ll;

#define endl "\n"
#define first st
#define second nd
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

int freq[ALPHABET_LEN];
string s1, s2;

string solve() {
    for (char c : s1) 
        freq[ctoi(c)]++;
    for (char c : s2) 
        freq[ctoi(c)]--;
    
    int diffs = 0;
    for (int i = 0; i < ALPHABET_LEN; i++) 
        diffs += abs(freq[i]);
    
    if (diffs == 0)
        return "ANAGRAMY";
    else if (diffs == 2)
        return "PRAWIE";
    else 
        return "NIE";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s1 >> s2;
    cout << solve() << endl;

    return 0;
}
