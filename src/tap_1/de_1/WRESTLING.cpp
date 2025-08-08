#include <bits/stdc++.h>
using namespace std;

int main() {
    int size;
    cin >> size;

    vector<int> posA(size + 1);
    for (int i = 1; i <= size; ++i) {
        int w;
        cin >> w;
        posA[w] = i;
    }

    // how many wrestlers align
    vector<int> cnt(size, 0);

    for (int i = 1; i <= size; ++i) {
        int wres;
        cin >> wres;
        int orig = posA[wres]; // where w was in A
        int shift = (i - orig + size) % size; // how far to rotate B
        cnt[shift]++; // incr count
    }

    int bestShift = 0;
    int bestCount = cnt[0];
    for (int s = 1; s < size; ++s) {
        if (cnt[s] > bestCount) {
            bestCount = cnt[s];
            bestShift = s;
        }
    }
    cout << bestShift << " " << bestCount << "\n";
    return 0;
}
