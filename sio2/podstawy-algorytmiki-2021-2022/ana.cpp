#include <bits/stdc++.h>
using namespace std;

string s1, s2;
#define ALPHABET_LEN 26
int freq1[ALPHABET_LEN], freq2[ALPHABET_LEN];

inline int ctoi(char c) { return c - 'a'; }

pair<string, string> solve() {
    pair<string, string> res;

    for (int i = 0; i < s1.length(); i++)
        freq1[ctoi(s1[i])]++;
    for (int i = 0; i < s2.length(); i++) 
        freq2[ctoi(s2[i])]++;

    for (int i = 0; i < ALPHABET_LEN; i++) {
        freq1[i] = min(freq1[i], freq2[i]);
        freq2[i] = freq1[i];
    }

    for (int i = 0; i < s1.length(); i++) {
        if (freq1[ctoi(s1[i])] > 0) {
            res.first.push_back(s1[i]);
            freq1[ctoi(s1[i])]--;
        }
    }

    for (int i = 0; i < s2.length(); i++) {
        if (freq2[ctoi(s2[i])] > 0) {
            res.second.push_back(s2[i]);
            freq2[ctoi(s2[i])]--;
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s1 >> s2;

    pair<string, string> res = solve();
    if (!res.first.length()) {
        cout << "BRAK\n";
    } else {
        cout 
            << res.first.length() << "\n" 
            << res.first << "\n"
            << res.second.length() << "\n" 
            << res.second << "\n";
    }

    return 0;
}
