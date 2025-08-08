#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases;
    cin >> cases;
    while (cases--) {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        int parts = 1;
        for (int i = 1; i < n; ++i) {
            if (a[i] - a[i - 1] > k) {
                parts++;
            }
        }

        cout << parts << "\n";
    }

    return 0;
}
