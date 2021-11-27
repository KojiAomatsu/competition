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
  rep(i, 0, N) {
    rep(i, 0, M) {
      ll ui, vi;
      cin >> ui >> vi;
      ui--;
      vi--;
      d.merge(ui, vi);
    }
  }
  if (N != M) {
    cout << 0 << endl;
    return 0;
  }

  ll sz = d.groups().size();
  ll ans = 1;
  rep(i, 0, sz) {
    ans *= 2;
    ans %= mod;
  }
  return ans;
}