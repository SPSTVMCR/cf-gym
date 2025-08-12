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
    int N;
    cin >> N;
    vll A(N + 1), prefix(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        prefix[i] = prefix[i - 1] + A[i];
    }

    unordered_map<ll, ll> min_pref;
    min_pref.reserve(N);
    ll answer = LLONG_MIN;

    for (int k = 1; k <= N; ++k) {
        ll v = A[k];
        if (min_pref.find(v) != min_pref.end()) {
            answer = max(answer, prefix[k] - min_pref[v]);
            min_pref[v] = min(min_pref[v], prefix[k - 1]);
        } else {
            min_pref[v] = prefix[k - 1];
        }
    }

    if (answer == LLONG_MIN) answer = 0;
    cout << answer;
    return 0;
}
