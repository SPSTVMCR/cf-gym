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
#define f(type, i, s, e) for (type i = (s); i < (e); i++)
#define minf(x, y) ((x) < (y) ? (x) : (y))
#define maxf(x, y) ((x) > (y) ? (x) : (y))
// bool prime(ll a) {if (a == 1) return 0; for (int i = 2; i <= round(sqrt(a)); ++i) if (a % i == 0) return false; return true;}
/* Problem functions */
struct Slot {
    int row{}, start{}, length{}, letterPos{};
    bool done = false;
};

/* Main function */
int main() {
    fast_io();

    int M, N;
    cin >> M >> N;
    vector<string> grid(M);
    f(int, i, 0, M) {
        cin >> grid[i];
    }

    vector<Slot> slots;
    f(int, i, 0, M) {
        int first = -1;
        f(int, c, 0, N) {
            if (grid[i][c] != '0' && grid[i][c] != '1') {
                first = c;
                break;
            }
        }
        if (first < 0) continue;
        int s = first, e = first;
        while (s > 0 && grid[i][s - 1] != '0') s--;
        while (e + 1 < N && grid[i][e + 1] != '0') e++;
        slots.push_back({i, s, e - s + 1, first - s});
    }
    vector<string> words(slots.size());
    f(size_t, i, 0, slots.size()) cin >> words[i];

    for (auto &word: words) {
        for (auto &sl: slots) {
            if (sl.done) continue;
            if (static_cast<int>(word.size()) != sl.length) continue;
            if (word[sl.letterPos] != grid[sl.row][sl.start + sl.letterPos])
                continue;
            for (int i = 0; i < sl.length; i++) {
                grid[sl.row][sl.start + i] = word[i];
            }
            sl.done = true;
            break;
        }
    }
    for (auto &row: grid) {
        cout << row << "\n";
    }
    return 0;
}
