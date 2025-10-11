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
ll validity(const vll& X, const vll& Y, const vll& M)
{
    ll count = 0;
    for (ll x : X) {
        for (ll y: Y){
            ll low = max(x, y);
            ll high = x + y - 1;
            if (low == high) continue;
            auto itL = lower_bound(all(M), low);
            auto itH = upper_bound(all(M), high);
            count += (itH - itL);
        }
    }
    return count;
}
/* Main function */
int main()
{
    fast_io();
    int n;
    cin >> n;
    vll arr_a(n), arr_b(n), arr_c(n);
    f(int, i, 0, n)
    {
        cin >> arr_a[i];
    }
    f(int, i, 0, n)
    {
        cin >> arr_b[i];
    }
    f(int, i, 0, n)
    {
        cin >> arr_c[i];
    }
    sort(all(arr_a));
    sort(all(arr_b));
    sort(all(arr_c));
    const int v1 = validity(arr_a, arr_b, arr_c);
    const int v2 = validity(arr_a, arr_c, arr_b);
    const int v3 = validity(arr_b, arr_c, arr_a);
    int res = v1 + v2 + v3;
    cout << res << '\n';
    return 0;
}
