#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> sides(n);
    for (int i = 0; i < n; ++i) {
        cin >> sides[i];
    }
    unordered_map<int, int> freq;
    for (int side: sides) {
        freq[side]++;
    }
    int equiCount = 0;
    for (auto &[side, count]: freq) {
        if (count >= 3) {
            equiCount += count / 3;
        }
    }
    cout << equiCount << " " << n - equiCount * 3 << "\n";
    return 0;
}
