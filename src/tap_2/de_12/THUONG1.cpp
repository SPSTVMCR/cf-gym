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

    ll n, m;
    cin >> n >> m;
    vll A(n);

    f(ll, i, 0, n) cin >> A[i];
    f(ll, i, 0, m) {
        ll inp;
        cin >> inp;
        auto it = find(all(A), inp);
        if (it != A.end()) {
            A.erase(it);
        }
    }

    vll B = A;
    sort(all(B));

    ll max_sum = 0;
    for (size_t i = 0, j; i < B.size(); ++i) {
        j = i + 1;
        while (j < B.size() && B[j] == B[i]) {
            ++j;
        }
        ll sum = B[i] * (j - i);
        max_sum = maxf(max_sum, sum);
        i = j - 1;
    }

    for (ll x: A) {
        cout << x << " ";
    }
    cout << "\n";
    cout << max_sum << "\n";
    return 0;
}
