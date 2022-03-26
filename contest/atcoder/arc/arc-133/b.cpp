#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll op(ll a, ll b) { return max(a, b); }

ll e() { return 0; }

int main() {
  ll N;
  cin >> N;
  vector<ll> P(N);
  vector<ll> Q(N);
  rep(i, 0, N) { cin >> P[i]; }
  atcoder::segtree<ll, op, e> seg(N + 1);

  map<ll, vector<ll>> idxs;
  rep(i, 0, N) {
    cin >> Q[i];
    rep(j, 1, sqrt(Q[i]) + 1) {
      if (Q[i] % j == 0) {
        idxs[j].push_back(i);
        if (Q[i] != j * j) {
          idxs[Q[i] / j].push_back(i);
        }
      }
    }
  }

  rep(i, 0, N) {
    ll num = P[i];
    for (int j = idxs[num].size() - 1; j >= 0; j--) {
      ll tow = idxs[num][j];
      ll mx = seg.prod(0, tow);
      seg.set(tow, mx + 1);
    }
  }

  ll ans = seg.all_prod();
  cout << ans << endl;
}