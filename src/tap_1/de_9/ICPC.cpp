#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    string P, verdict;
    unordered_map<string,int> wrongCount;
    unordered_set<string> solved;
    int solvedCount = 0;
    int totalTime = 0;
    while (cin >> T) {
        if (T == -1) break;
        cin >> P >> verdict;
        if (solved.count(P)) continue;
        if (verdict == "wrong") {
            wrongCount[P]++;
        } else if (verdict == "right") {
            solved.insert(P);
            solvedCount++;
            totalTime += T + wrongCount[P] * 20;
        }
    }
    cout << solvedCount << " " << totalTime;
    return 0;
}
