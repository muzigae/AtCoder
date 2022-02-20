#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<int> abc(26, 0);

    string w; cin >> w;
    for (auto letter : w) abc[letter - 'a']++;
    for (auto s : abc) {
        if (s % 2) return !(cout << "No");
    } cout << "Yes";
    return 0;
}
