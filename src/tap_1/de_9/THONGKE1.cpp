// main.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> birthyears;
    birthyears.reserve(n);

    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);

        string yearStr;
        for (char c: line) {
            if (isdigit(c)) {
                yearStr += c;
            }
        }

        birthyears.push_back(stoi(yearStr));
    }

    sort(birthyears.begin(), birthyears.end());

    vector<int> gaps;
    for (int i = 1; i < n; ++i) {
        gaps.push_back((birthyears[i]) - (birthyears[i - 1] + 1));
    }
    int maxGap = *max_element(gaps.begin(), gaps.end());
    cout << maxGap << endl;
    for (int i = 1; i < n; ++i) {
        if ((birthyears[i] - birthyears[i - 1] - 1) == maxGap) {
            cout << birthyears[i - 1] + 1 << " " << birthyears[i] - 1 << endl;
            break;
        }
    }
}
