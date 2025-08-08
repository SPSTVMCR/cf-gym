#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool uniqueDgts(ll num) {
    string s = to_string(num);
    set<char> digits(s.begin(), s.end());
    return digits.size() == s.size();
}

int main() {
    ll x;
    cin >> x;
    x++;
    while (!uniqueDgts(x)) {
        x++;
    }

    cout << x << endl;
    return 0;
}