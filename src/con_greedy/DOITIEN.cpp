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

/* Main function */
int main()
{
    fast_io();
    ll n;
    cin >> n;
    ll m[] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    f(ll, i, 0, n)
    {
        ll x;
        cin >> x;
        ll res = 0;
        f(int, i, 0, 10) {
            res += x / m[i];
            x %= m[i];
        }
        cout << res << '\n';
    }

    return 0;
}
