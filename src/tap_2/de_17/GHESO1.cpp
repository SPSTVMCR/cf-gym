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
#define f(type, i, s, e) for (type i = (s); i < (e); ++i)
#define minf(x, y) ((x) < (y) ? (x) : (y))
#define maxf(x, y) ((x) > (y) ? (x) : (y))
// bool prime(ll a) {if (a == 1) return 0; for (int i = 2; i <= round(sqrt(a)); ++i) if (a % i == 0) return false; return true;}
/* Problem functions */

/* Main function */
int main() {
    fast_io();
    int A, B;
    cin >> A >> B;

    for (int N = 2; N <= 200; ++N) {
        for (int x = 1; x < N; ++x) {
            int y = N - x;
            if ((A * x + B * y) % 9 != 0) continue;

            int cntA = x, cntB = y;
            int d1 = min(A, B), d2 = max(A, B);
            int cnt1 = (d1 == A ? cntA : cntB);
            int cnt2 = (d2 == A ? cntA : cntB);
            string result;

            if (d1 == 0) {
                result.push_back(static_cast<char>('0' + d2));
                --cnt2;
                result.append(cnt1, '0');
                result.append(cnt2, static_cast<char>('0' + d2));
            } else {
                result.append(cnt1, static_cast<char>('0' + d1));
                result.append(cnt2, static_cast<char>('0' + d2));
            }

            cout << result;
            return 0;
        }
    }

    cout << -1;
    return 1;
}
