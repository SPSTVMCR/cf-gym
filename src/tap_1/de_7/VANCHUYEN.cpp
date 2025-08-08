#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, Ta, Tb, K;
    cin >> N >> M >> Ta >> Tb >> K;

    vector<int> A(N), B(M);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int j = 0; j < M; ++j) {
        cin >> B[j];
    }

    if (K >= N || K >= M) {
        cout << -1 << '\n';
        return 1;
    }

    int maxTime = -1;
    for (int i = 0; i <= K; ++i) {
        if (i >= N || i >= M) {
            continue;
        }
        int startA = A[i] + Ta;
        int endB = B[M - K + i - 1] + Tb;
        if (startA <= B[M - K + i - 1]) {
            maxTime = max(maxTime, endB);
        }
    }

    cout << maxTime << '\n';

    return 0;
}
