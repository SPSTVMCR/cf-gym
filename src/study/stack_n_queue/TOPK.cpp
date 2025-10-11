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
struct Comp {
    bool operator()(const pair<ll, int>& a, const pair<ll, int>& b)
    {
        if (a.first != b.first) {
            return a.first < b.first; // by value
        }
        return a.second > b.second; // then by index
    }
};
/* Main function */
int main()
{
    fast_io();
    ll n, k;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, Comp> pq;
    cin >> n >> k;
    f(ll, i, 0, n){
        pair<ll, int> inp;
        cin >> inp.first;
        inp.second = i + 1;
        pq.push(inp);
    }
    f(int, i, 0, k){
        auto [idx, val] = pq.top();
        cout << val << ' ' << idx << '\n';
        pq.pop();
    }
    return 0;
}