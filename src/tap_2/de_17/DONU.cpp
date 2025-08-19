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
#define f(type, i, s, e) for (type i = (s); i < (e); ++i)
#define minf(x, y) ((x) < (y) ? (x) : (y))
#define maxf(x, y) ((x) > (y) ? (x) : (y))
// bool prime(ll a) {if (a == 1) return 0; for (int i = 2; i <= round(sqrt(a)); ++i) if (a % i == 0) return false; return true;}
/* Problem functions */

/* Main function */
int main() {
    fast_io();

    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    if (k >= n) cout << n << "\n";

    vi left1s(n), right1s(n);
    f(int, i, 0, n) {
        if (s[i] == '1') {
            if (i == 0) {
                left1s[i] = 1;
            } else {
                left1s[i] = left1s[i - 1] + 1;
            }
        } else {
            left1s[i] = 0;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '1') {
            if (i == n - 1) {
                right1s[i] = 1;
            } else {
                right1s[i] = right1s[i + 1] + 1;
            }
        } else {
            right1s[i] = 0;
        }
    }
    ll best = 0;
    for (int l = 0; l + k - 1 < n; ++l) {
        int r = l + k - 1;
        ll leftRun = (l > 0) ? left1s[l - 1] : 0;
        ll rightRun = (r + 1 < n) ? right1s[r + 1] : 0;
        ll total = leftRun + rightRun + k;
        best = max(best, total);
    }
    cout << best << "\n";

    return 0;
}



