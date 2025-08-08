#include <bits/stdc++.h>

using namespace std;

int main() {
    string inp;
    cin >> inp;
    vector<int> nums;

    for (size_t i = 0; i < inp.size(); ++i) {
        string numStr;
        while (i < inp.size() && isdigit(inp[i])) {
            numStr += inp[i];
            ++i;
        }
        if (!numStr.empty()) {
            nums.push_back(stoi(numStr));
        }
    }

    sort(nums.begin(), nums.end(), greater<int>());

    cout << nums[0] << endl;
    return 0;
}
