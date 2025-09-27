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
// bool prime(ll a) {if (a == 1) return 0; for (int i = 2; i <= round(sqrt(a));
// ++i) if (a % i == 0) return false; return true;}
/* Problem functions */

/* Main function */
int main()
{
    fast_io();
    // 1st line: total days
    // 2nd line: energy bonus if rest day
    // 3rd line: energy loss if exercise day
    // out: maximum exercise days
    // total energy of rest must be equal to total energy of exercise

    ll d, r, e;
    cin >> d >> r >> e;
    if (r + e == 0) {
        cout << d << '\n';
    }
    else {
        ll num = d * r;
        ll den = r + e;
        if (num % den == 0) {
            cout << (num / den) << '\n';
        }
        else {
            cout << -1 << '\n';
        }
    }

    return 0;
}
