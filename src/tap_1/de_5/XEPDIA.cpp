#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> durability(n);
    for (int i = 0; i < n; ++i) {
        cin >> durability[i];
    }

    sort(durability.begin(), durability.end());

    int maxStack = 1;
    for (int i = 0; i < n; ++i) {
        if (durability[i] >= maxStack) {
            maxStack++;
        }
    }

    cout << maxStack << '\n';

    return 0;
}