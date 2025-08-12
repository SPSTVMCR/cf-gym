///SPSTVMCR - wip
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

    ll x;
    cin >> x;
    vll red;
    vll blue;
    f(ll, i, 0, x) {
        ll inp;
        cin >> inp;
        if (inp < 0) {
            red.push_back(inp);
        } else {
            blue.push_back(-inp);
        }
    }
    sort(all(red));
    sort(all(blue));

    return 0;
}