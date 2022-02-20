#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k, x, y; cin >> n >> k >> x >> y;
    if (n >= k) cout << x * k + y * (n - k);
    else cout << x * n;
    return 0;
}
