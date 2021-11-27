#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll mod = 998244353;

int main() {
  ll N, M;
  cin >> N >> M;
  atcoder::dsu d(N);
  vector<ll> digits(N);
  rep(i, 0, M) {
    ll ui, vi;
    cin >> ui >> vi;
    ui--;
    vi--;
    d.merge(ui, vi);
    digits[ui]++;
    digits[vi]++;
  }
  if (N != M) {
    cout << 0 << endl;
    return 0;
  }

  ll sz = d.groups().size();
  for (auto gs : d.groups()) {
    ll sz = gs.size();
    ll es = 0;
    for (auto v : gs) {
      es += digits[v];
    }
    es /= 2;
    if (sz != es) {
      cout << 0 << endl;
      return 0;
    }
  }
  ll ans = 1;
  rep(i, 0, sz) {
    ans *= 2;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}