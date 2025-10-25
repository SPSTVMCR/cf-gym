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
void solve() {
    string s;
    ll k;
    cin >> k;
    cin >> s;
    // value of s is the sum of the squared freq of each character
    // find minimum value of s after removing k characters
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    } // freq count
    priority_queue<int> pq;
    for (auto p : freq) {
        pq.push(p.second);
    }    while (k-- && !pq.empty()) {
        ll top = pq.top();
        pq.pop();
        top--;
        if (top > 0) {
            pq.push(top);
        }
    }
    ll ans = 0;
    while (!pq.empty()) {
        ll top = pq.top();
        pq.pop();
        ans += top * top;
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