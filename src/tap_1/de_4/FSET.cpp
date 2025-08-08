#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    if (!(cin >> n >> m)) {
        return 0;
    }
    vector<int> spf(n + 1);
    for (int i = 2; i <= n; ++i) {
        if (!spf[i]) {
            for (int j = i; j <= n; j += i) {
                if (!spf[j]) {
                    spf[j] = i;
                }
            }
        }
    }
    vector<int> sf(n + 1);
    sf[1] = 1;
    for (int i = 2; i <= n; ++i) {
        int p = spf[i];
        int t = i / p;
        if (t % p == 0) {
            sf[i] = sf[t / p];
        } else {
            sf[i] = sf[t] * p;
        }
    }
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; ++i) {
        cnt[sf[i]]++;
    }
    ll res = 1;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] > 0) {
            res = (res * (cnt[i] + 1)) % m;
        }
    }
    cout << res;
    return 0;
}
