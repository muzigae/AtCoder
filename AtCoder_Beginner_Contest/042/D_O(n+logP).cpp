#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
using vll = vector<ll>;

#define mod 1000000007

ll exp(ll x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;
    if (n % 2) return x * exp(x * x % mod, (n - 1) / 2) % mod;
    return exp(x * x % mod, n / 2) % mod;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int h, w, a, b; cin >> h >> w >> a >> b;

    vll fac(200001); fac[0] = 1;
    for (int i = 1; i <= 200000; i++) fac[i] = fac[i - 1] * i % mod;

    vll inv(200001); inv[200000] = exp(fac[200000], mod - 2);
    for (int i = 200000; i > 0; i--) inv[i - 1] = inv[i] * i % mod;

    vll v(w - b);
    for (int i = 0; i < w - b; i++) {
        v[i] = fac[(h - a - 1) + (i + b)] * inv[h - a - 1] % mod * inv[i + b] % mod;
    }

    ll total = 0;
    for (int i = 0; i < w - b; i++) {
        total += v[i] * fac[(a - 1) + (w - b - 1 - i)] % mod * inv[a - 1] % mod * inv[w - b - 1 - i] % mod;
    } cout << total % mod;
    return 0;
}
