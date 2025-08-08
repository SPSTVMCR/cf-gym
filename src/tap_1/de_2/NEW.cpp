#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, a, b;
    cin >> n >> a >> b;

    ll ans = 0;
    for (ll S = n; S <= a + b; S += n) {
        ll lzero = 0;
        ll low = max(lzero, S - b);
        ll high = min(a, S);
        if (high >= low)
            ans += high - low + 1;
    }
    cout << ans << endl;
    return 0;
}
