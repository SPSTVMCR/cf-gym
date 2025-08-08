#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    ll totalPairs = n * (n - 1) / 2;
    ll oddCnt = n / 2;
    ll oddPairs = oddCnt * (oddCnt - 1) / 2;
    ll validPairs = totalPairs - oddPairs;
    cout << validPairs << '\n';

    return 0;
}
