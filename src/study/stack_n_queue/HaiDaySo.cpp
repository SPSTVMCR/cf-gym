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
    ll a, b, k;
    cin >> a >> b >> k;
    vll arr_a(a);
    vll arr_b(b);
    priority_queue<ll, vll, greater<ll>> pq;
    f(ll, i, 0, a)
    {
        cin >> arr_a[i];
    }
    f(ll, j, 0, b)
    {
        cin >> arr_b[j];
    }
    f(ll, x, 0, a)
    {
        f(ll, y, 0, b)
        {
            pq.push(arr_a[x] + arr_b[y]);
        }
    }
    f(ll, m, 0, k)
    {
        cout << pq.top() << '\n';
        pq.pop();
    }

    return 0;
}