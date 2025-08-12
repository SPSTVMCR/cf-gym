///SPSTVMCR
#include <bits/stdc++.h>
using namespace std;
//Types
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
//Fast I/O
#define fast_io() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//Utils
#define all(x) (x).begin(), (x).end()
#define f(i, s, e) for (int i = (s); i < (e); ++i)
#define minf(x, y) ((x) < (y) ? (x) : (y))
#define maxf(x, y) ((x) > (y) ? (x) : (y))
bool prime(ll a) {if (a == 1) return 0; for (int i = 2; i <= round(sqrt(a)); ++i) if (a % i == 0) return false; return true;}
/* Problem functions */

/* Main function */
int main() {
    fast_io();
    ll K;
    cin >> K;
    ll count = 0;
    for (ll x = 2; x <= K / 3; ++x) {
        if (!prime(x)) continue;
        for (ll y = x; y <= (K - x) / 2; ++y) {
            if (!prime(y)) continue;
            ll z = K - x - y;
            if (z < y || !prime(z)) continue;
            count++;
        }
    }
    cout << count << endl;
    return 0;
}