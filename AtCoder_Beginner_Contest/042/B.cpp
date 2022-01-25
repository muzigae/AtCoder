#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int n, l;
bool cps(string a, string b) {
    for (int i = 0; i < l; i++) {
        if (a[i] != b[i]) return a[i] < b[i];
    } return a[0] < b[0];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> l;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end(), cps);
    for (auto i : v) cout << i;
    return 0;
}
