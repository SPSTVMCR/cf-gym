//XAUHH
//2 str => 2 bool vec => check each char in str => if not present => del++
#include <bits/stdc++.h>
using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    vector<bool> in1(26), in2(26);
    for (char chr: str1) {
        in1[chr - 'a'] = true;
    }
    for (char chr: str2) {
        in2[chr - 'a'] = true;
    }

    int dels = 0;
    for (char chr: str1) {
        if (!in2[chr - 'a']) {
            dels++;
        }
    }
    for (char chr: str2) {
        if (!in1[chr - 'a']) {
            dels++;
        }
    }
    cout << dels << endl;
    return 0;
}
