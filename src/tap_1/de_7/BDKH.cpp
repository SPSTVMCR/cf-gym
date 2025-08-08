//Wrong answer, fix later
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;
    vector<ll> locations(m);
    for (int i = 0; i < m; ++i) {
        cin >> locations[i];
    }
    vector<ll> heights(m, 0), a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }

    for (int i = 0; i < n; ++i) {
        int l = lower_bound(locations.begin(), locations.end(), a[i]) - locations.begin();
        int r = upper_bound(locations.begin(), locations.end(), b[i]) - locations.begin() - 1;
        bool incr = true;
        for (int j = l; j <= r; ++j) {
            heights[j] += incr ? c[i] : -c[i];
            incr = !incr;
        }
    }

    for (ll h: heights) {
        cout << h << "\n";
    }
    return 0;
}
