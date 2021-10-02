#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll op(ll a, ll b) { return max(a, b); }

ll e() { return 0; }

int main() {
  ll N, M;
  cin >> N >> M;
  vector<P> A(M);
  rep(i, 0, M) {
    ll ai, bi;
    cin >> ai >> bi;
    A[i] = {ai, bi};
  }
  sort(A.begin(), A.end(), [](pair<ll, ll> a, pair<ll, ll> b) {
    if (a.first != b.first) {
      return a.first < b.first;
    } else {
      return a.second > b.second;
    }
  });

  atcoder::segtree<ll, op, e> seg(N + 1);

  rep(i, 0, M) {
    ll tow = A[i].second;
    ll mx = seg.prod(0, tow);
    seg.set(tow, mx + 1);
  }

  ll ans = seg.all_prod();
  cout << ans << endl;
}