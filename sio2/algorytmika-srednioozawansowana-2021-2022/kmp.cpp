#include <bits/stdc++.h>
using namespace std;

using uint = unsigned;
using ll   = long long;
using ull  = unsigned ll;

#define endl  "\n"
#define first  st
#define second nd

inline int ctoi(char c) { return c - 'a'; }
template<class T> inline T mod(T a, T m) { return (a % m + m) % m; }
template<class T> inline T pow(T a, T b, T m) { T res = 1; while (b) { if (b&1) { res = (res * a) % m; a = (a * a) % m; b >>= 1; } } }
template<class T> inline T pow(T a, T b) { return pow(a, b, numeric_limits<T>::max()); }
template<class T> inline T gcd(T a, T b) { T t; while (b) { a = a % b; t = a; a = b; b = t; } return a; }
template<class T> inline T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<typename Arr, typename Len> inline void print_container(const Arr& arr, const Len len, const char* sep) {
    for (Len i = 0; i < len; i++)
        cout << arr[i] << sep;
    cout << endl;
}

const int maxN = 8e5;
int len_pat, len_txt;
string pat, txt;

vector<int> make_lps(const string& str) {
    int n = str.length();
    vector<int> lps(n, 0);	
	int len = 0, i = 1;
	while (i < n)
		if (str[i] == str[len])
			lps[i++] = ++len;
		else if (len == 0) 
            lps[i++] = 0;
        else
            len = lps[len - 1];
	return lps;
}

vector<int> solve() {
    vector<int> lps = make_lps(pat + "$" + txt);
    vector<int> ans;
    for (int i = len_pat + 1; i <= len_pat + len_txt; i++)  /* n + 1 is where the text starts */
        if (lps[i] == len_pat) 
            ans.push_back(1 + i - (len_pat - 1) - (len_pat + 1));
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> len_pat >> len_txt >> pat >> txt;

    auto ans = solve();
    print_container(ans, ans.size(), endl);

    return 0;
}