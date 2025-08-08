#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> sides(n);
    for (int i = 0; i < n; ++i) {
        cin >> sides[i];
    }

    unordered_map<int, int> freq;
    for (int x: sides) {
        freq[x]++;
    }

    vector<int> lens;
    for (auto &kv: freq) {
        lens.push_back(kv.first);
    }
    sort(lens.begin(), lens.end());

    int m = lens.size();
    vector<ll> pref(m + 1, 0);
    for (int i = 0; i < m; ++i) {
        pref[i + 1] = pref[i] + freq[lens[i]];
    }

    ll isoCount = 0;
    for (int i = 0; i < m; ++i) {
        int L = lens[i];
        int c = freq[L];
        if (c < 2) continue;
        if (c >= 3) {
            isoCount += (ll) c * (c - 1) * (c - 2) / 6;
        }
        ll pairs = (ll) c * (c - 1) / 2;

        int idx = lower_bound(lens.begin(), lens.end(), 2 * L) - lens.begin();
        ll totalLess = pref[idx];

        ll candidates = totalLess - c;

        isoCount += pairs * candidates;
    }

    cout << isoCount << "\n";
    return 0;
}
