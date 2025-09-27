/// SPSTVMCR
#include <bits/stdc++.h>
using namespace std;
// Types
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
// Fast I/O
#define fast_io()                                                                                  \
    ios::sync_with_stdio(false);                                                                   \
    cin.tie(nullptr);                                                                              \
    cout.tie(nullptr);
// Utils
#define all(x) (x).begin(), (x).end()
#define f(type, i, s, e) for (type i = (s); i < (e); ++i)
#define minf(x, y) ((x) < (y) ? (x) : (y))
#define maxf(x, y) ((x) > (y) ? (x) : (y))
// bool prime(ll a) {if (a == 1) return 0; for (int i = 2; i <= round(sqrt(a)); ++i) if (a % i == 0)
// return false; return true;}
/* Problem functions */
string verify(string inp)
{
    stack<char> stk_char;
    for (char c : inp) {
        if (c == '(' || c == '{' || c == '[') {
            stk_char.push(c);
        }
        else {
            char top = stk_char.top();
            if ((c == ')' && top == '(') || (c == '}' && top == '{') || (c == ']' && top == '[')) {
                stk_char.pop();
            }
            else {
                return "FALSE";
            }
        }
    }
    if (stk_char.empty()) {
        return "TRUE";
    }
    else {
        return "FALSE";
    }
}
/* Main function */
int main()
{
    fast_io();

    string x;
    cin >> x;
    
    cout << verify(x) << endl;
    return 0;
}