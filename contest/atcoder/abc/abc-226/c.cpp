#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<ll> vis(N + 1, false);
  vector<vector<ll>> edges(N + 1);
  vector<ll> times(N + 1);
  rep(i, 0, N) {
    ll Ti, Ki;
    cin >> Ti >> Ki;
    times[i] = Ti;
    ll need = 0;
    rep(j, 0, Ki) {
      int Ai;
      cin >> Ai;
      edges[i].push_back(Ai - 1);
    }
  }
  queue<ll> q;
  set<ll> se;
  q.push(N - 1);
  se.insert(N - 1);
  while (!q.empty()) {
    ll t = q.front();
    q.pop();
    for (auto e : edges[t]) {
      if (se.find(e) == se.end()) {
        q.push(e);
        se.insert(e);
      }
    }
  }
  ll ans = 0;
  for (auto s : se) {
    ans += times[s];
  }
  cout << ans << endl;
}
