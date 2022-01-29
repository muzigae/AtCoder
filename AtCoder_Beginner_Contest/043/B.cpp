#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s; cin >> s;
    vector<char> v;
    for (auto i : s) {
        if (i == 'B') {
            if (v.size()) v.pop_back();
        }
        else v.push_back(i);
    }
    for (auto i : v) cout << i;
    return 0;
}
