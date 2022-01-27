#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
using vll = vector<ll>;

#define mod 1000000007

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int h, w, a, b; cin >> h >> w >> a >> b;

    vll fac(200001), ifac(200001), inv(200001);
    fac[0] = 1; ifac[0] = 1; inv[1] = 1;
    for (int i = 1; i <= 200000; i++) {
        fac[i] = fac[i - 1] * i % mod;
        if (i >= 2)
            inv[i] = (-mod / i) * inv[mod % i] % mod;
        ifac[i] = ifac[i - 1] * (inv[i] + mod) % mod;
    }

    vll v(w - b);
    for (int i = 0; i < w - b; i++) {
        v[i] = fac[(h - a - 1) + (i + b)] * ifac[h - a - 1] % mod * ifac[i + b] % mod;
    }

    ll total = 0;
    for (int i = 0; i < w - b; i++) {
        total += v[i] * fac[(a - 1) + (w - b - 1 - i)] % mod * ifac[a - 1] % mod * ifac[w - b - 1 - i] % mod;
    } cout << total % mod;
    return 0;
}
