//CHUDE
#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("CHUDE.INP", "r", stdin);
    //freopen("CHUDE.OUT", "w", stdout);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    set<int> uniqueElements(arr.begin(), arr.end());
    cout << uniqueElements.size() << endl;

    return 0;
}
