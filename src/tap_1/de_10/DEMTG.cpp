#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll d, n;
    cin >> d >> n;
    ll type1 = (d + 1) // cac phan cua BC
               * (d + 2) // tong 2 canh ben
               / 2;
    ll type2 = n + 1;
    ll res = type1 * type2;

    cout << res;
    return 0;
}
