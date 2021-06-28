#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

// 拡張ユークリッドの互除法 実装例

ll extgcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll gcd = extgcd(b, a % b, x, y);
  ll oldX = x;
  x = y;
  y = oldX - a / b * y;
  return gcd;
}

ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  ll t;
  cin >> t;
  rep(i, 0, t) {
    ll N, S, K;
    cin >> N >> S >> K;
    ll g1 = gcd(N, K);
    ll g = gcd(g1, S);
    N = N / g;
    S = S / g;
    K = K / g;
    ll gp = gcd(K, N);
    if (gp != 1) {
      cout << -1 << endl;
      continue;
    }
    ll x, y, w;
    w = extgcd(K, N, x, y);
    ll ans = x * (N - S) % N;
    if (ans < 0) {
      ans += N;
    }
    cout << ans << endl;
  }
}