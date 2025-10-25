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
string SumOf(string a, string b)
{
    // bring them to the same length
    while (a.size() < b.size())
        a = '0' + a;
    while (b.size() < a.size())
        b = '0' + b;
    int len = a.size();
    string res = "";
    // carry variable
    ll crr = 0;
    for (int i = len - 1; i >= 0; --i) {
        ll sum = (a[i] - '0') + (b[i] - '0') + crr;
        res = char((sum % 10) + '0') + res;
        crr = sum / 10;
    }
    if (crr > 0)
        return to_string(crr) + res;
    return res;
}
/* Main function */
int main()
{
    fast_io();

    string x, y;
    cin >> x >> y;
    // greedy minimum
    f(int, i, 0, x.size())
    {
        if (x[i] == '6')
            x[i] = '5';
    }
    f(int, i, 0, y.size())
    {
        if (y[i] == '6')
            y[i] = '5';
    }
    cout << SumOf(x, y) << ' ';
    // greedy maximum
    f(int, i, 0, x.size())
    {
        if (x[i] == '5')
            x[i] = '6';
    }
    f(int, i, 0, y.size())
    {
        if (y[i] == '5')
            y[i] = '6';
    }
    cout << SumOf(x, y) << '\n';

    return 0;
}