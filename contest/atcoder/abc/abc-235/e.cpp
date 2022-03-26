#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, M, Q;
  cin >> N >> M >> Q;
  vector<pair<ll, P>> weis;
  rep(i, 0, M) {
    ll ai, bi, ci;
    cin >> ai >> bi >> ci;
    weis.push_back(make_pair(ci, make_pair(ai, bi)));
  }
  sort(weis.begin(), weis.end());
  atcoder::dsu d(N + 1);
  map<ll, ll> append_order_map;
  vector<ll> ordered_wei;
  rep(i, 0, weis.size()) {
    auto e = weis[i];
    if (e.second.first == e.second.second) continue;
    if (!d.same(e.second.first, e.second.second)) {
      d.merge(e.second.first, e.second.second);
      ordered_wei.push_back(e.first);
      if (append_order_map.find(e.second.first) == append_order_map.end()) {
        append_order_map[e.second.first] = ordered_wei.size() - 1;
      }
      if (append_order_map.find(e.second.second) == append_order_map.end()) {
        append_order_map[e.second.second] = ordered_wei.size() - 1;
      }
    }
  }

  rep(i, 0, Q) {
    ll ui, vi, wi;
    cin >> ui >> vi >> wi;
    ll mx = max(append_order_map[ui], append_order_map[vi]);
    bool ans = false;
    if (ordered_wei[mx] > wi) ans = true;
    if (ui == vi) ans = false;
    cout << (ans ? "Yes" : "No") << endl;
  }
}