#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) {
        return 1;
    }
    vector<ll> A(N + 2);
    vector<ll> profit(N + 2);
    ll peakPrice = 0;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    profit[N + 1] = 0;

    for (int i = N; i >= 1; i--) {
        peakPrice = max(peakPrice, A[i]);
        profit[i] = profit[i + 1] + (peakPrice - A[i]);
    }

    int queryCount;
    cin >> queryCount;
    while (queryCount--) {
        int T;
        cin >> T;
        cout << profit[T] << '\n';
    }
    return 0;
}
