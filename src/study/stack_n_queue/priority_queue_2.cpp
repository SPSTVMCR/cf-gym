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

/* Main function */
int main()
{
    fast_io();
    priority_queue<ll, vll> pq;

    ll n, k;
    cin >> n >> k;
    f(ll, i, 0, n)
    {
        ll inp;
        cin >> inp;
        pq.push(inp);
    }

    f(int, i, 0, k)
    {
        cout << pq.top() << '\n';
        pq.pop();
    }

    cout << '\n';

    return 0;
}
