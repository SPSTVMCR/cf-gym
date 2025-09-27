/// SPSTVMCR
#include <bits/stdc++.h>
using namespace std;
// Types
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using str = string;
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
str reverse(str inp) {
    stack<char> stk_char;
    str rev;
    for (char c : inp) {
        stk_char.push(c);
    }
    while (!stk_char.empty()) {
        rev.push_back(stk_char.top());
        stk_char.pop();
    }
    return rev;
}
/* Main function */
int main()
{
    fast_io();

    str x;
    cin >> x;
    cout << reverse(x) << endl;

    return 0;
}