#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll lcm_ll(ll a, ll b) {
    return a / std::gcd(a, b) * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll blue, blueLn, red, redLn, purple, purpleLn, yellow, yellowLn;
    cin >> blue >> blueLn
    >> red >> redLn
    >> purple >> purpleLn
    >> yellow >> yellowLn;

    ll lcmWidth = lcm_ll(blueLn, purpleLn);
    ll maxWidth = min(blue * blueLn, purple * purpleLn);
    ll widthFactor = maxWidth / lcmWidth;
    if (widthFactor == 0) {
        cout << 0;
        return 1;
    }
    ll width = widthFactor * lcmWidth;
    ll numGreen = width / blueLn;
    ll numPurple = width / purpleLn;

    ll lcmHeight = lcm_ll(redLn, yellowLn);
    ll maxHeight = min(red * redLn, yellow * yellowLn);
    ll heightFactor = maxHeight / lcmHeight;
    if (heightFactor == 0) {
        cout << 0;
        return 1;
    }
    ll height = heightFactor * lcmHeight;
    ll numRed = height / redLn;
    ll numYellow = height / yellowLn;
    ll area = width * height;

    cout << area << '\n';
    return 0;
}
