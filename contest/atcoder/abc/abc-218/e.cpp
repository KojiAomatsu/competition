#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, M;
  cin >> N >> M;
  vector<vector<P>> edges(N); // to, weight
  vector<bool> vis(N, false);
  priority_queue<P, vector<P>, greater<P>> enables; // weight, to
  ll minusc = 0;

  ll loopW = 0;
  ll all = 0;
  rep(i, 0, M) {
    ll ai, bi, ci;
    cin >> ai >> bi >> ci;
    ai--;
    bi--;

    if (ai == bi) {
      if (ci > 0) loopW += ci;
      continue;
    }
    edges[ai].push_back({bi, ci});
    edges[bi].push_back({ai, ci});
    all += ci;
    if (ci <= 0) {
      minusc += ci;
    }
  }
  ll used = 0;

  vis[0] = true;
  for (auto em : edges[0]) {
    enables.push({em.second, em.first});
  }
  while (!enables.empty()) {
    P em = enables.top();
    enables.pop();
    if (!vis[em.second]) {
      vis[em.second] = true;
      used += em.first;
      if (em.first <= 0) {
        minusc -= em.first;
      }
      for (auto nem : edges[em.second]) {
        if (!vis[nem.first]) {
          enables.push({nem.second, nem.first});
        }
      }
    }
  }
  ll ans = all - used + loopW - minusc;
  cout << ans << endl;
}
