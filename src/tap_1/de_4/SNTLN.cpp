#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string T;
    if (!getline(cin, T)) {
        return 1;
    }
    const int LIMIT = 100000;
    vector<bool> is_prime(LIMIT, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < LIMIT; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < LIMIT; j += i)
                is_prime[j] = false;
        }
    }
    int res = 0;
    int n = T.size();
    for (int i = 0; i < n; ++i) {
        if (!isdigit(T[i])) {
            continue;
        }
        int num = 0;
        for (int j = i; j < n && j < i + 5 && isdigit(T[j]); ++j) {
            num = num * 10 + (T[j] - '0');
            if (num >= LIMIT) {
                break;
            }
            if (is_prime[num] && num > res) {
                res = num;
            }
        }
    }
    cout << res << endl;
    return 0;
}
