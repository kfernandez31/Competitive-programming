#include <bits/stdc++.h>
using namespace std;

const int maxN = 5e5;
int n, ones;
bool counter[maxN + 20];

int log2(int x) {
    int exp = -1;
    while (x > 0) { 
        x >>= 1; 
        exp++; 
    }
    return exp;
}

void add(int x) {
    x += 1;
    counter[x] ^= 1;
    bool carry = counter[x] == 0;

    if (counter[x] == 0) {
        ones--;
    } else {
        ones++;
    }
    
    while (carry) {
        x++;
        counter[x] ^= 1;
        carry = counter[x] == 0;

        if (counter[x] == 0) {
            ones--;
        } else {
            ones++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    while (n--) {
        int x;
        cin >> x;
        add(x);
        cout << ones << "\n";
    }

    return 0;
}
