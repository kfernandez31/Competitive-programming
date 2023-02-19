#include <bits/stdc++.h>
using namespace std;

#define ALPHABET_LEN 26

const int maxN = 1e6;
string word;
int k;
int letter_cnt[ALPHABET_LEN];

inline int ctoi(char c) {
    return c - 'a';
}

inline bool condition(int cnt_diff) {
    return cnt_diff >= k;
}

pair<int, int> caterpillar() {
    pair<int, int> result = {-1, -1};
    int min_res = INT_MAX,
        tail = 0,
        head = 0,
        cnt_diff = 1;

    if (k == 1 && word.length() > 0) {
        return {1, 1};
    }

    letter_cnt[ctoi(word[0])] = 1;
    while (head < word.length()) {
        if (!condition(cnt_diff)) {
            head++;
            if (head < word.length()) {
                letter_cnt[ctoi(word[head])]++;
                if (letter_cnt[ctoi(word[head])] == 1) {
                    cnt_diff++;
                }
            }
        } else {
            int min_now = head - tail + 1;
            if (min_now < min_res) {
                result = {tail + 1, head + 1};
                min_res = min_now;
            }
            letter_cnt[ctoi(word[tail])]--;
            if (letter_cnt[ctoi(word[tail])] == 0) {
                cnt_diff--;
            }
            tail++;
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> word >> k;

    pair<int, int> res = caterpillar();
    if (res.first != -1 && res.second != -1) {
        cout << res.first << " " << res.second << "\n";
    } else {
        cout << "BRAK" << "\n";
    }

    return 0;
}