#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s; cin >> s;
    if (s.size() == 2) {
        if (s[0] == s[1]) return !(cout << 1 << " " << 2);
    }
    else {
        for (int i = 0; i < s.size() - 2; i++) {
            int cnt = 0;
            for (int j = 1; j < 3; j++) {
                if (s[i] == s[i + j]) cnt++;
            }
            if (cnt) return !(cout << i + 1 << " " << i + 3);
        }
    } cout << -1 << " " << -1;
    return 0;
}
