//special prime number validity: if we remove any digit (right to left order removal), the number should still be prime
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<bool> is_prime(10e6 + 1, true);
void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= 10e6; ++i) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= 10e6; j += i) {
                is_prime[j] = false;
            }
        }
    }
}
bool is_special_prime(ll x) {
    string s = to_string(x);
    for (int i = 0; i < s.size(); ++i) {
        ll num = stoll(s.substr(0, s.size() - i));
        if (!is_prime[num]) {
            return false;
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x;
    cin >> x;
    sieve();

    if (is_special_prime(x)) {
        cout << "PHAI" << "\n";
    } else {
        cout << "KHONG" << "\n";
    }

    return 0;
}