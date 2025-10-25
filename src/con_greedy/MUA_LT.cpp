/// SPSTVMCR
#include <bits/stdc++.h>
using namespace std;
// Types
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
// Fast I/O
#define fast_io()                                                                                  \
    ios::sync_with_stdio(false);                                                                   \
    cin.tie(nullptr);                                                                              \
    cout.tie(nullptr);
// Utils
#define all(x) (x).begin(), (x).end()
#define f(type, i, s, e) for (type i = (s); i < (e); ++i)
#define minf(x, y) ((x) < (y) ? (x) : (y))
#define maxf(x, y) ((x) > (y) ? (x) : (y))
// bool prime(ll a) {if (a == 1) return 0; for (int i = 2; i <= round(sqrt(a)); ++i) if (a % i == 0)
// return false; return true;}
/* Problem functions */
void solve()
{
    short n, s, m;
    cin >> n >> s >> m;
    short wd = s - s / 7;
    short need = m * s;
    if (n * wd < need) {
        cout << -1;
    }
    else {
        short ans = (need + n - 1) / n;
        cout << ans;
    }
    cout << '\n';
}
/* Main function */
int main()
{
    fast_io();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}