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
bool prime(ll a) {if (a == 1) return 0; for (int i = 2; i <= round(sqrt(a)); ++i) if (a % i == 0) return false; return true;}
/* Problem functions */

/* Main function */
int main() {
    fast_io();
    ll x;
    cin >> x;
    vll ans(x);
    f(i, 0, x) {
        cin >> ans[i];
    }
    map<ll, ll> freq;
    for (ll num : ans) {
        freq[num]++;
    }
    ll groups = 0;
    for (const auto& [num, count] : freq) {
        if (count % num == 0) {
            groups += count / num;
        }
    }
    cout << groups << endl;
    return 0;
}
