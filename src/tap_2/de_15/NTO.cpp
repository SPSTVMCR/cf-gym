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
// bool prime(ll a) {if (a == 1) return 0; for (int i = 2; i <= round(sqrt(a)); ++i) if (a % i == 0) return false; return true;}
/* Problem functions */
string prime_fact(ll n) {
    string res;
    if (n < 2) return "1";
    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            if (!res.empty()) res += "*";
            res += to_string(i);
            n /= i;
        }
    }
    if (n > 1) {
        if (!res.empty()) res += "*";
        res += to_string(n);
    }
    return res;
}
string divisors_count(ll n) {
    ll count = 0;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            count += 2;
            if (i * i == n) count--;
        }
    }
    return to_string(count);
}
/* Main function */
int main() {
    fast_io();

    ll x;
    cin >> x;
    vll dataset(x);
    f(i, 0, x) {
        cin >> dataset[i];
    }
    f(i, 0, x) {
        string res = divisors_count(dataset[i]) + " " + prime_fact(dataset[i]);
        cout << res << endl;
    }
    return 0;
}