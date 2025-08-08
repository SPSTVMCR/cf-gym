#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Returns true if all values in nums have the same remainder mod m
bool isValid(const vector<ll> &nums, ll m) {
    ll r = nums[0] % m;
    for (ll x: nums)
        if (x % m != r)
            return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    ll g = llabs(nums[1] - nums[0]);
    vector<ll> divisors;
    for (int i = 2; i < n; ++i)
        g = gcd(g, llabs(nums[i] - nums[0]));
    for (ll i = 2; i * i <= g; ++i) {
        if (g % i == 0) {
            divisors.push_back(i);
            if (i != g / i)
                divisors.push_back(g / i);
        }
    }
    if (g > 1) {
        divisors.push_back(g);
    }
    sort(divisors.begin(), divisors.end());

    for (ll d: divisors) {
        if (isValid(nums, d))
            cout << d << " ";
    }
    cout << "\n";

    return 0;
}
