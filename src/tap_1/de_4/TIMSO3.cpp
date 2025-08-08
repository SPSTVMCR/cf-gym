#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ld = long double;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ull n;
    ui x0;
    if (!(cin >> n)) return 1;
    cin >> x0;
    ui x = x0;
    ull t = 1;
    for (ui p = 2; (ull) p * p <= x; ++p) {
        if (x % p == 0) {
            int c = 0;
            while (x % p == 0) {
                x /= p;
                ++c;
            }
            if (c % 2) t *= p;
        }
    }
    if (x > 1) {
        t *= x;
    }
    ull m = (t != 0) ? (n / t) : 0;
    ull s = floor(sqrt((ld) m));
    while ((u128) (s + 1) * (s + 1) <= m) {
        ++s;
    }
    while ((u128) s * s > m) {
        --s;
    }
    cout << s;
    return 0;
}
