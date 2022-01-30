#include <iostream>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

int dp[41][1 << 17];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, x, y, z; cin >> n >> x >> y >> z;
    int max_bit = (1 << x + y + z) - 1;
    int haiku = (1 << x - 1) | (1 << x + y - 1) | (1 << x + y + z - 1);

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= max_bit; j++) {
            for (int k = 1; k <= 10; k++) {
                int seq = (1 << k - 1) | (j << k);
                seq &= max_bit;
                if ((seq & haiku) != haiku) {
                    dp[i][seq] += dp[i - 1][j];
                    dp[i][seq] %= mod;
                }
            }
        }
    }

    ll total = 1;
    for (int i = 1; i <= n; i++) total = total * 10 % mod;
    for (int i = 0; i <= max_bit; i++) total = (total - dp[n][i] + mod) % mod;
    cout << total;
    return 0;
}
