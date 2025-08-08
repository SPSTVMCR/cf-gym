#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    //factorial of n
    ll fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    //return the first to k digits of the factorial
    string factStr = to_string(fact);
    if (k > factStr.size()) {
        cout << "0" << endl;
    } else {
        cout << factStr.substr(0, k) << endl;
    }

    return 0;
}