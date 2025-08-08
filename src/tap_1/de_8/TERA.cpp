#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll L;
    cin >> n >> L;
    vector<ll> b(n), r(n), p(n), y(n);
    for (ll &x: b) cin >> x;
    for (ll &x: r) cin >> x;
    for (ll &x: p) cin >> x;
    for (ll &x: y) cin >> x;

    int count = 0;
    unordered_map<ll, ll> br, py;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            br[b[i] + r[j]]++;
        }
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            py[p[i] + y[j]]++;
        }
    }
    for (const auto &kv : br) {
        ll target = L - kv.first;
        if (py.find(target) != py.end()) {
            count += kv.second * py[target];
        }
    }
    cout << count << "\n";


    return 0;
}
