#include <bits/stdc++.h>
using namespace std;

string wallpaper;

int solve() {
    int min_dist = INT_MAX, cur_dist = 0;
    char cur_char = '*';
    for (int i = 0; i < wallpaper.length(); i++) {
        if (cur_char == '*') {
            cur_char = wallpaper[i];
            cur_dist = 0;
        } else {
            cur_dist++;
            if (wallpaper[i] != '*') {
                if (wallpaper[i] != cur_char) {
                    min_dist = min(min_dist, cur_dist - 1);
                    cur_char = wallpaper[i]; 
                }
                cur_dist = 0;
            }
        }
    }
    return min_dist == INT_MAX? 1 : wallpaper.length() - min_dist;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> wallpaper;
    cout << solve() << "\n";
    
    return 0;
}