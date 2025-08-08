#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, q;
    cin >> n >> x >> q;
    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    while (q--) {
        int l, r, count = 0;
        cin >> l >> r;
        for (int i = l - 1; i < r; ++i) {
            if (values[i] > 0 && values[i] < x) {
                ++count;
            }
        }
        cout << count << '\n';
    }

    return 0;
}
