#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<set<ll>> edges(N);
  map<P, ll> weigts;
  vector<ll> digs(N, 0);
  vector<ll> nodes(N, 1);
  rep(i, 0, N - 1) {
    ll ui, vi, wi;
    cin >> ui >> vi >> wi;
    ui--;
    vi--;
    weigts[{ui, vi}] = wi;
    weigts[{vi, ui}] = wi;

    edges[ui].insert(vi);
    edges[vi].insert(ui);
    digs[ui]++;
    digs[vi]++;
  }
  ll ans = 0;
  ll rem = N;
  while (rem != 2) {
    rep(i, 0, N) {
      if (rem == 2) break;
      ll di = digs[i];
      if (di != 1) continue;
      for (auto par : edges[i]) { // ひとつしかない
        ans += weigts[{i, par}] * nodes[i];
        nodes[par]++;
        rem--;
      }
    }
  }
  vector<ll> ns;
  rep(i, 0, N) {
    if (digs[i] == 1) {
      ns.push_back(i);
    }
  }
  ans += ns[0] * ns[1] * weigts[{ns[0], ns[1]}];
  cout << ans << endl;
}