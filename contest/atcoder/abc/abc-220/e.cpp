#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll twos[2200000];
ll mod = 998244353;

int main() {
  ll N, D;
  cin >> N >> D;

  twos[0] = 1;
  rep(i, 0, 2000000) {
    twos[i + 1] = 2 * twos[i];
    twos[i + 1] %= mod;
  }

  ll ans = 0;
  rep(i, 0, D + 1) {
    ll mx = max(i, D - i);
    if (N < mx) continue;
    ll cas = twos[N - mx] - 1;
    ll alcas = (((cas * twos[max(i - 1, 0ll)]) % mod) * twos[max(D - i - 1, 0ll)]) % mod;
    ans += alcas;
    ans %= mod;
  }
  ans *= 2;
  ans %= mod;
  cout << ans << endl;
}