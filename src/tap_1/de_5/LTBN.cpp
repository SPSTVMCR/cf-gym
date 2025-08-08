#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int highestExp(ll value) {
    if (value <= 1)
        return 1;
    if (value % 10 == 0)
        return static_cast<int>(log10(value));

    int bestExp = 1;
    for (ll base = 2; base <= value; ++base) {
        ll p = base;
        int exp = 1;
        while (p < value) {
            p *= base;
            ++exp;
        }
        if (p == value && exp > bestExp) {
            bestExp = exp;
        }
    }
    return bestExp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x, y, z;
    cin >> x >> y >> z;
    ll n = x * y * z;

    cout << highestExp(n) << '\n';
    return 0;
}
