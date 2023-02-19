#include <bits/stdc++.h>
using namespace std;

const int maxN = 2 * 1e5;
const int maxH = 5 * 1e5;
int N, H;

int mury[maxN];
int wysOdDolu[maxH + 1], wysOdGory[maxH + 1], przebiciaOdDolu[maxH + 1], przebiciaOdGory[maxH + 1];
int minPrzebic = INT_MAX, ilePozycji;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> H;

    for (int i = 0; i < N; i++) {
        cin >> mury[i];
        if (i % 2 == 0)
            wysOdDolu[mury[i]]++;
        else
            wysOdGory[mury[i]]++;
    }

    przebiciaOdDolu[H] = wysOdDolu[H];
    for (int i = H-1; i >= 1; i--) {
        przebiciaOdDolu[i] = przebiciaOdDolu[i+1] + wysOdDolu[i];
    }

    przebiciaOdGory[1] = wysOdGory[H];
    for (int i = 2; i <= H; i++) {
        przebiciaOdGory[i] = przebiciaOdGory[i-1] + wysOdGory[H+1-i];
    }

    for (int i = 1; i <= H; i++) {
        int przebicia = przebiciaOdGory[i] + przebiciaOdDolu[i];
        if (przebicia < minPrzebic) {
            minPrzebic = przebicia;
            ilePozycji = 1;
        }
        else if (przebicia == minPrzebic)
            ilePozycji++;
    }

    cout << minPrzebic << " " << ilePozycji << "\n";
    return 0;
}
