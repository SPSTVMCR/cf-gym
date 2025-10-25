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
    int s, d;
    cin >> s >> d;
    string ans;
    if (s == 0) {
        if (d == 1)
            cout << "0\n";
        else
            cout << "-1\n";
        return;
    }
    if (s > 9 * d) {
        cout << "-1\n";
        return;
    }
    f(int, i, 0, d) {
        for (int j = (i == 0 ? 1 : 0); j <= 9; ++j) {
            int rem = s - j;
            int remPos = d - i - 1;
            if (rem >= 0 && remPos * 9 >= rem) {
                ans.push_back(char('0' + j));
                s -= j;
                break;
            }
        }
    }
    cout << ans << '\n';
}
/* Main function */
int main()
{
    fast_io();

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}