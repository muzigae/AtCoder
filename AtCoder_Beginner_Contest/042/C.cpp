#include <iostream>
#include <string>
#include <queue>
using namespace std;
using vi = vector<int>;

bool cps(string x, string y) {
    int xl = x.size(), yl = y.size();
    if (xl != yl) return xl < yl;
    else {
        for (int i = 0; i < xl; i++) {
            if (x[i] != y[i]) return x[i] < y[i];
        } return 1;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string n; int k; cin >> n >> k;
    vi digit(10, 1), num;
    for (int i = 0; i < k; i++) {
        int a; cin >> a; digit[a] = 0;
    }
    for (int i = 0; i < 10; i++) {
        if (digit[i]) num.push_back(i);
    }

    queue<string> Q; Q.push("");
    while (!Q.empty()) {
        string iroha = Q.front(); Q.pop();
        if (cps(n, iroha)) {
            cout << iroha; break;
        }
        for (auto d : num) {
            if (iroha == "" && d == 0) continue;
            Q.push(iroha + to_string(d));
        }
    }
    return 0;
}
