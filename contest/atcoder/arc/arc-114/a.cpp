#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  ll N;
  cin >> N;
  vector<ll> X(N);
  rep(i, 0, N) { cin >> X[i]; }
  vector<ll> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
  ll ans = 1E18;

  // bit全探索 実装例 bit 全探索
  rep(i, 1, 1 << primes.size()) {
    ll nu = 1;
    rep(j, 0, primes.size()) {
      if (i & (1 << j)) {
        nu *= primes[j];
      }
    }
    bool fl = true;
    rep(k, 0, N) {
      if (gcd(nu, X[k]) == 1) {
        fl = false;
      }
    }
    if (fl) {
      ans = min(ans, nu);
    }
  }
  cout << ans << endl;
}