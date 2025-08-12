///SPSTVMCR
#include <bits/stdc++.h>
using namespace std;
//Types
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
//Fast I/O
#define fast_io() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//Utils
#define all(x) (x).begin(), (x).end()
#define f(i, s, e) for (int i = (s); i < (e); ++i)
#define minf(x, y) ((x) < (y) ? (x) : (y))
#define maxf(x, y) ((x) > (y) ? (x) : (y))
bool prime(ll a) {if (a == 1) return 0; for (int i = 2; i <= round(sqrt(a)); ++i) if (a % i == 0) return false; return true;}
/* Problem functions */
typedef struct {
    ll a;
    ll b;
    ll c;
} AnsSet;
ll calcDistance(const AnsSet& ansSet) {
    ll x = ansSet.a;
    ll y = ansSet.b;
    ll z = ansSet.c;
    ll dif_xy = y - x;
    ll dif_yz = z - y;
    ll dif_xz = z - x;
    if (x == y && y == z) {
        return 0;
    } else if (x == y) {
        if (dif_yz > 1) return (dif_yz - 2) * 2;
        else return (dif_yz - 1) * 2;
    } else if (y == z) {
        if (dif_xy > 1) return (dif_xy - 2) * 2;
        else return (dif_xy - 1) * 2;
    } else {
        return (dif_yz - 1) + (dif_xy - 1) + (dif_xz - 2);
    }

}
/* Main function */
int main() {
    fast_io();
    ll x;
    cin >> x;
    vector<AnsSet> ans(x);
    f(i, 0, x) {
        cin >> ans[i].a >> ans[i].b >> ans[i].c;
    }
    for (auto& ansSet : ans) {
        if (ansSet.a > ansSet.b) swap(ansSet.a, ansSet.b);
        if (ansSet.b > ansSet.c) swap(ansSet.b, ansSet.c);
        if (ansSet.a > ansSet.b) swap(ansSet.a, ansSet.b);
    }
    for (const auto& ansSet : ans) {
        cout << calcDistance(ansSet) << endl;
    }
    return 0;
}
