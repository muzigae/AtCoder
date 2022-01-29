#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, max_p = -100, min_p = 100, total; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        max_p = max(max_p, v[i]);
        min_p = min(min_p, v[i]);
    }
    for (int i = min_p; i <= max_p; i++) {
        int cost = 0;
        for (auto j : v) cost += (j - i) * (j - i);
        if (i == min_p) total = cost;
        else total = min(total, cost);
    } cout << total;
    return 0;
}
