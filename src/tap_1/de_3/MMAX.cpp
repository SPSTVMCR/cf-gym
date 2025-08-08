#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }
    sort(values.begin(), values.end());
    ll maxTwo = values[n - 1] * values[n - 2];
    ll maxThree1 = values[n - 1] * values[n - 2] * values[n - 3];
    ll maxThree2 = values[0] * values[1] * values[n - 1];

    cout << max({maxTwo, maxThree1, maxThree2});
    return 0;
}
