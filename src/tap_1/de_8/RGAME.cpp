#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int datasets;
    cin >> datasets;
    while (datasets--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x: a) {
            cin >> x;
        }

        unordered_map<int, int> freq;
        for (int x: a) {
            freq[x]++;
        }

        vector<int> sides;
        for (auto &kv: freq) {
            int len = kv.first;
            int pairs = kv.second / 2;
            for (int i = 0; i < pairs; ++i)
                sides.push_back(len);
        }

        ll m = sides.size();
        ll rectangleCount = m * (m - 1) / 2;

        vector<pair<int, int> > rects;
        rects.reserve(rectangleCount);
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                rects.emplace_back(sides[i], sides[j]);
            }
        }
        // Find recs with max area => difference between two sides should be min
        if (rects.empty()) {
            cout << "-1\n";
            break;
        } else if (rects.size() == 1) {
            cout << rects[0].first * rects[0].second << "\n";
            continue;
        } else {
            sort(rects.begin(), rects.end(),
                 [](const pair<int, int> &a, const pair<int, int> &b) {
                     return
                             abs(a.first - a.second) < abs(b.first - b.second); // true if a is better
                 });
            ll maxArea = 0;
            for (const auto &rect: rects) {
                ll area = static_cast<ll>(rect.first) * rect.second;
                if (area > maxArea) {
                    maxArea = area;
                }
            }
            cout << maxArea << "\n";
        }
    }
    return 0;
}
