/// SPSTVMCR
#include <bits/stdc++.h>
using namespace std;
// Types
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
// Fast I/O
#define fast_io()                \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
// Utils
#define all(x) (x).begin(), (x).end()
#define f(type, i, s, e) for (type i = (s); i < (e); ++i)
#define minf(x, y) ((x) < (y) ? (x) : (y))
#define maxf(x, y) ((x) > (y) ? (x) : (y))
/* Main function */
int main()
{
    fast_io();

    int N;
    if (!(cin >> N))
        return 0;
    vector<pair<ll, ll>> pts;
    pts.reserve(N);
    vll xs, ys;
    xs.reserve(N);
    ys.reserve(N);

    for (int i = 0; i < N; ++i)
    {
        ll x, y;
        cin >> x >> y;
        pts.emplace_back(x, y);
        xs.push_back(x);
        ys.push_back(y);
    }

    // xy process
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    int Xn = (int)xs.size();
    int Yn = (int)ys.size();

    vector<vll> ysOfX(Xn);
    vector<vll> xsOfY(Yn);

    for (auto &p : pts)
    {
        ll x = p.first, y = p.second;
        int xi = int(lower_bound(xs.begin(), xs.end(), x) - xs.begin());
        int yi = int(lower_bound(ys.begin(), ys.end(), y) - ys.begin());
        ysOfX[xi].push_back(y);
        xsOfY[yi].push_back(x);
    }
    for (int i = 0; i < Xn; ++i)
        sort(ysOfX[i].begin(), ysOfX[i].end());
    for (int i = 0; i < Yn; ++i)
        sort(xsOfY[i].begin(), xsOfY[i].end());

    sort(pts.begin(), pts.end());

    auto exist = [&](ll x, ll y) -> int
    {
        return binary_search(pts.begin(), pts.end(), make_pair(x, y)) ? 1 : 0;
    };
    auto countYOnX = [&](ll x, ll y1, ll y2) -> ll
    {
        if (y1 > y2)
            return 0;
        auto itx = lower_bound(xs.begin(), xs.end(), x);
        if (itx == xs.end() || *itx != x)
            return 0;
        int xi = int(itx - xs.begin());
        auto &vec = ysOfX[xi];
        auto L = lower_bound(vec.begin(), vec.end(), y1);
        auto R = upper_bound(vec.begin(), vec.end(), y2);
        return R - L;
    };
    auto countXOnY = [&](ll y, ll x1, ll x2) -> ll
    {
        if (x1 > x2)
            return 0;
        auto ity = lower_bound(ys.begin(), ys.end(), y);
        if (ity == ys.end() || *ity != y)
            return 0;
        int yi = int(ity - ys.begin());
        auto &vec = xsOfY[yi];
        auto L = lower_bound(vec.begin(), vec.end(), x1);
        auto R = upper_bound(vec.begin(), vec.end(), x2);
        return R - L;
    };

    int P;
    cin >> P;
    while (P--)
    {
        ll X1, Y1, X2, Y2;
        cin >> X1 >> Y1 >> X2 >> Y2;
        if (X1 > X2)
            swap(X1, X2);
        if (Y1 > Y2)
            swap(Y1, Y2);

        // Degenerate cases
        if (X1 == X2 && Y1 == Y2)
        {
            cout << exist(X1, Y1) << "\n";
            continue;
        }
        if (X1 == X2)
        {
            cout << countYOnX(X1, Y1, Y2) << "\n";
            continue;
        }
        if (Y1 == Y2)
        {
            cout << countXOnY(Y1, X1, X2) << "\n";
            continue;
        }

        ll leftCount = countYOnX(X1, Y1, Y2);
        ll rightCount = countYOnX(X2, Y1, Y2);
        ll bottomCount = countXOnY(Y1, X1, X2);
        ll topCount = countXOnY(Y2, X1, X2);

        int c1 = exist(X1, Y1);
        int c2 = exist(X1, Y2);
        int c3 = exist(X2, Y1);
        int c4 = exist(X2, Y2);
        ll ans = leftCount + rightCount + bottomCount + topCount - (c1 + c2 + c3 + c4);
        cout << ans << "\n";
    }
    return 0;
}