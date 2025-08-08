#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> nums(n);
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            nums[i] = n;
        } else {
            nums[i] = nums[i - 1] + (2 * (n - 1) - 2 * (i - 1));
        }
    }
    ll res = accumulate(nums.begin(), nums.end(), 0);
    cout << res << endl;
    return 0;
}