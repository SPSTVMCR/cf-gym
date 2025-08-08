#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    long long a, b;
    cin >> a >> b;
    if (a > b) {
        swap(a, b);
    }
    ll count = (b / 10) - ((a - 1) / 10);

    cout << count << endl;
    return 0;
}
