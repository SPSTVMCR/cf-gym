#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll start, end;
    ll divisor1, divisor2;
    cin >> start >> end >> divisor1 >> divisor2;

    ll gcdVal = gcd(divisor1, divisor2);
    ll lcmVal = (divisor1 / gcdVal) * divisor2;
    ll count = end / lcmVal - (start - 1) / lcmVal;

    cout << count << '\n';
    return 0;
}
