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
ll sum(const vll& v) {
    ll total = 0;
    for (const auto& val : v) {
        total += val;
    }
    return total;
}
#define switch_index(x) switch (x) { case 0: sect_1_used = true; break; case 1: sect_2_used = true; break; case 2: sect_3_used = true; break;}
/* Main function */
int main() {
    fast_io();
    bool sect_1_used = false;
    bool sect_2_used = false;
    bool sect_3_used = false;
    vll hc(3);
    vll tc(3);
    vll vc(3);
    ll count_hc_move = 0;
    ll count_tc_move = 0;
    ll count_vc_move = 0;
    f(i, 0, 3) {
        cin >> hc[i] >> tc[i] >> vc[i];
    }
    //huu co
    ll max_hc = *max_element(all(hc));
    int max_index_hc = max_element(all(hc)) - hc.begin();
    switch_index(max_index_hc);
    count_hc_move = sum(hc) - max_hc;
    //tai che
    ll max_tc = *max_element(all(tc));
    int max_index_tc = max_element(all(tc)) - tc.begin();
    if (max_index_tc == 0 && sect_1_used) {
        maxf(tc[1], tc[2]);
        max_index_tc = (tc[1] > tc[2]) ? 1 : 2;
    } else if (max_index_tc == 1 && sect_2_used) {
        maxf(tc[0], tc[2]);
        max_index_tc = (tc[0] > tc[2]) ? 0 : 2;
    } else if (max_index_tc == 2 && sect_3_used) {
        maxf(tc[0], tc[1]);
        max_index_tc = (tc[0] > tc[1]) ? 0 : 1;
    }
    switch_index(max_index_tc);
    count_tc_move = sum(tc) - max_tc;
    //vo co
    int max_index_vc = 0;
    if (!sect_1_used) {
        max_index_vc = 0;
    } else if (!sect_2_used) {
        max_index_vc = 1;
    } else if (!sect_3_used) {
        max_index_vc = 2;
    }
    switch_index(max_index_vc);
    count_vc_move = sum(vc) - vc[max_index_vc];
    ll total_moves = count_hc_move + count_tc_move + count_vc_move;
    cout << total_moves << endl;

    return 0;
}
