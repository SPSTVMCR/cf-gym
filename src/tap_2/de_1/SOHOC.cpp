#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_prime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}


int main() {
    ll x;
    cin >> x;
    ll start = sqrt(x);
    if (start * start < x) {
        start++;
    }
    while (start > 1) {
        if (is_prime(start)) {
            cout << start * start << endl;
            return 0;
        }
        start++;
    }
    return 1;
}
